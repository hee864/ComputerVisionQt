#include "mainframe.h"
#include "ui_mainframe.h"
#include "imageform.h"

#include <QFileDialog>
#include <QPainter>
#include <sstream>
#include <fstream>
#include <QMessageBox>
using namespace std;

MainFrame::MainFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainFrame)
{
    ui->setupUi(this);

    _q_pFormFocused     = 0;

    //객체 맴버의 초기화


    //리스트 출력창을 안보이게    
    ui->listWidget->setVisible(false);
    this->adjustSize();

    //UI 활성화 갱신
    UpdateUI();
}

MainFrame::~MainFrame()
{ 
    delete ui;         

    for(auto& item : _lImageForm)
        delete item;

}

void MainFrame::CloseImageForm(ImageForm *pForm)
{
    //ImageForm 포인터 삭제
    unsigned int idx = std::find(_lImageForm.begin(), _lImageForm.end(), pForm) - _lImageForm.begin();
    if(idx != _lImageForm.size())
    {
        delete _lImageForm[idx];
        _lImageForm.erase(_lImageForm.begin() + idx);
    }

    //활성화 ImageForm 초기화
    _q_pFormFocused     = 0;

    //관련 객체 삭제

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::UpdateUI()
{    
    if(ui->tabWidget->currentIndex() == 0)
    {
    }
    else if(ui->tabWidget->currentIndex() == 1)
    {  
    }
    else if(ui->tabWidget->currentIndex() == 2)
    {

    }
    else if(ui->tabWidget->currentIndex() == 3)
    {
    }
}

void MainFrame::OnMousePos(const int &nX, const int &nY, ImageForm* q_pForm)
{
}

void MainFrame::focusInEvent(QFocusEvent * event)
{
    Q_UNUSED(event) ;

    UpdateUI();
}

void MainFrame::closeEvent(QCloseEvent* event)
{
    //생성된 ImageForm을 닫는다.
    for(int i=0; i< _lImageForm.size(); i++)
        delete _lImageForm[i];

    //리스트에서 삭제한다.
    _lImageForm.clear();
}


void MainFrame::on_buttonOpen_clicked()
{
    //이미지 파일 선택
    QFileDialog::Options    q_Options   =  QFileDialog::DontResolveSymlinks  | QFileDialog::DontUseNativeDialog; // | QFileDialog::ShowDirsOnly
    QString                 q_stFile    =  QFileDialog::getOpenFileName(this, tr("Select a Image File"),  "./data", "Image Files(*.bmp *.ppm *.pgm *.png)",0, q_Options);

    if(q_stFile.length() == 0)
        return;

    //이미지 출력을 위한 ImageForm 생성    
    ImageForm*              q_pForm   = new ImageForm(q_stFile, "OPEN", this);

    _lImageForm.push_back(q_pForm);
    q_pForm->show();

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonDeleteContents_clicked()
{
    //생성된 ImageForm을 닫는다.
    for(int i=_lImageForm.size()-1; i>=0; i--)
        delete _lImageForm[i];

    //리스트에서 삭제한다.
    _lImageForm.clear();

    //객체 삭제


    ui->listWidget->clear();
}

void MainFrame::on_tabWidget_currentChanged(int index)
{
    static int nOld = -1;

    if(nOld == 0)
    {

    }
    else if(nOld == 1)
    {

    }
    nOld = index;

    //UI 활성화 갱신
    UpdateUI();
}

void MainFrame::on_buttonShowList_clicked()
{
    static int nWidthOld = ui->tabWidget->width();

    if(ui->listWidget->isVisible())
    {
        nWidthOld = ui->listWidget->width();
        ui->listWidget->hide();
        this->adjustSize();
    }
    else
    {        
        ui->listWidget->show();
        QRect q_rcWin = this->geometry();

        this->setGeometry(q_rcWin.left(), q_rcWin.top(), q_rcWin.width()+nWidthOld, q_rcWin.height());
    }
}

void MainFrame::on_pushOstu_clicked()
{
    KImageGray igMain =_q_pFormFocused->ImageGray();
    KImageGray igBin;
    KBINARIZATION_OUTPUT* opBinOutput=KHisto().Ostu(&igMain,&igBin);

    ImageForm* q_pForm=0;
    for(auto item: _lImageForm)
        if(item->ID()=="Binary Image"&&item->size()==_q_pFormFocused->size())
        {
            q_pForm=item;
            break;
        }
    if(q_pForm)
        q_pForm->update();

    else
    {
        q_pForm=new ImageForm(igBin,"Binary Image",this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    ui->spinOstu->setValue(opBinOutput->nThresh);
    ui->listWidget->addItem(QString(">>Ostu Threshold: %1").arg(opBinOutput->nThresh));
    ui->listWidget->show();

    UpdateUI();
}


void MainFrame::on_pushThresholding_clicked()
{
    KImageGray igMain=_q_pFormFocused->ImageGray();
    igMain.Thresholded(ui->spinOstu->value());

    ImageForm* q_pForm=0;
    for(auto item: _lImageForm)
        if(item->ID()=="Binary Image"&&item->size()==_q_pFormFocused->size())
        {
            q_pForm=item;
            break;
        }
    if(q_pForm)
        q_pForm->update();

    else
    {
        q_pForm=new ImageForm(igMain,"Binary Image",this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }

    ui->listWidget->addItem(QString(">> Manual Threshold: %1").arg(ui->spinOstu->value()));
    ui->listWidget->show();

    UpdateUI();
}



void MainFrame::on_contrastTransform_clicked()
{
    if(_q_pFormFocused==0 || _q_pFormFocused->ImageColor().Address()==0||_q_pFormFocused->ID()!="OPEN")
        return;

    int contrastA=ui->spinContrastA->value();
    int contrastB=ui->spinContrastB->value();
    int contrastAp=0;
    int contrastBp=255;

    KImageColor colorImg=_q_pFormFocused->ImageColor().ContrastTransform(contrastA,contrastB,contrastAp,contrastBp);

    ImageForm* q_pForm=0;
    for(auto item:_lImageForm)
        if(item->ID()=="Contrast Transform"&& item->size()==_q_pFormFocused->size())
        {
            q_pForm=item;
            break;
        }

    if(q_pForm)
        q_pForm->Update(colorImg);
    else
    {
        q_pForm=new ImageForm(colorImg,"Contrast Transform",this);
        q_pForm->show();
        _lImageForm.push_back(q_pForm);
    }
    UpdateUI();

}

void MainFrame::on_pushDilation_clicked()
{
     int KernelSize=3;
    if(ui->Kernel3->isChecked()){
        KernelSize=3;
    }
    else if (ui->Kernel5->isChecked()){
        KernelSize=5;
    }

    KImageGray igBin=_q_pFormFocused->ImageGray().BinaryDilate(_WHITE,KernelSize);

    ImageForm* _q_pForm=0;
    for(auto item:_lImageForm)
        if(item->ID()=="Binary Image"&&item->size()==_q_pFormFocused->size())
        {
            _q_pForm=item;
            break;
        }

    if(_q_pForm)
        _q_pForm->Update(igBin);
    else
    {
        _q_pForm=new ImageForm(igBin,"Binary Image",this);
        _q_pForm->show();
        _lImageForm.push_back(_q_pForm);
    }
    UpdateUI();

}


void MainFrame::on_pushErosion_clicked()
{
    int KernelSize=3;

    if(ui->Kernel3->isChecked()){
        KernelSize=3;
    }
    else if (ui->Kernel5->isChecked()){
        KernelSize=5;
    }
    KImageGray igBin=_q_pFormFocused->ImageGray().BinaryErode(_WHITE,KernelSize);

    ImageForm* _q_pForm=0;
    for(auto item:_lImageForm)
        if(item->ID()=="Binary Image"&&item->size()==_q_pFormFocused->size())
        {
            _q_pForm=item;
            break;
        }

    if(_q_pForm)
        _q_pForm->Update(igBin);
    else
    {
        _q_pForm=new ImageForm(igBin,"Binary Image",this);
        _q_pForm->show();
        _lImageForm.push_back(_q_pForm);
    }
    UpdateUI();
}


void MainFrame::on_pushLabel_clicked()
{
    int NeighborSize;
    if (ui->neighbor4->isChecked()){
        NeighborSize=4;
    }
    else if(ui->neighbor8->isChecked()){
        NeighborSize=8;
    }
    int numLabels = 0;  // 라벨 수를 저장할 변수
    KImageColor igBin = _q_pFormFocused->ImageGray().BinaryLabelling(NeighborSize, numLabels);

    // 라벨 수를 리스트 위젯에 표시
    ui->spinLabel->setValue(numLabels);  // spinLabel에 라벨 수 설정
    ui->listWidget->addItem(QString("Number of Labels: %1").arg(numLabels));
    ui->listWidget->show();

    ImageForm* _q_pForm = nullptr;
    for (auto item : _lImageForm) {
        if (item->ID() == "Labeled Image" && item->size() == _q_pFormFocused->size()) {
            _q_pForm = item;
            break;
        }
    }
    if (_q_pForm) {
        _q_pForm->Update(igBin);
    } else {
        _q_pForm = new ImageForm(igBin, "Labeled Image", this);
        _q_pForm->show();
        _lImageForm.push_back(_q_pForm);
    }
    UpdateUI();
}


void MainFrame::on_pushOpen_clicked()
{
    int kernelsize;
    if(ui->KernelSize3) {
        kernelsize=3;
    }
    else if(ui->KernelSize5->isChecked()){
        kernelsize=5;
    }
    // 원본 이미지를 열림 연산(BinaryOpen) 적용
    KImageGray igBin = _q_pFormFocused->ImageGray().BinaryOpen(_WHITE, kernelsize);

    // 항상 새로운 창을 만들어서 결과 이미지를 표시
    ImageForm* _q_pForm = new ImageForm(igBin, "Binary Image Result", this);
    _q_pForm->show();
    _lImageForm.push_back(_q_pForm);

    // UI 업데이트
    UpdateUI();


}


void MainFrame::on_pushClose_clicked()
{
    int kernelsize;
    if(ui->KernelSize3) {
        kernelsize=3;
    }
    else if(ui->KernelSize5->isChecked()){
        kernelsize=5;
    }
    // 원본 이미지를 열림 연산(BinaryClose) 적용
    KImageGray igBin = _q_pFormFocused->ImageGray().BinaryClose(_WHITE, kernelsize);

    // 항상 새로운 창을 만들어서 결과 이미지를 표시
    ImageForm* _q_pForm = new ImageForm(igBin, "Binary Image Result", this);
    _q_pForm->show();
    _lImageForm.push_back(_q_pForm);

    // UI 업데이트
    UpdateUI();
}


void MainFrame::on_pushBoundary_clicked()
{
    int neighborsize;
    int ground;

    // 경계 유형 선택 (배경 또는 전경)
    if(ui->background->isChecked()) {
        ground = 0;  // 배경 경계 추출
    }
    else if(ui->foreground->isChecked()) {
        ground = 1;  // 전경 경계 추출
    }
    // 이웃 크기 선택 (4-이웃 또는 8-이웃)
    if(ui->Neighbor4->isChecked()) {
        neighborsize = 4;  // 4-이웃
    }
    else if(ui->Neighbor8->isChecked()) {
        neighborsize = 8;  // 8-이웃
    }

    // 현재 포커스된 이미지 가져오기
    KImageGray igInput = _q_pFormFocused->ImageGray();

    // 경계 추출 알고리즘 적용 (BinaryBoundaryExtraction은 별도로 구현)
    KImageGray igBoundary = igInput.BinaryBoundaryExtraction(ground, neighborsize);

    // 결과 이미지를 새로운 창에 표시
    ImageForm* _q_pForm = new ImageForm(igBoundary, "Boundary Image", this);
    _q_pForm->show();
    _lImageForm.push_back(_q_pForm);

    // UI 업데이트
    UpdateUI();
}


void MainFrame::on_button_HE_clicked()
{
    // Check if an image is currently loaded
    if (_q_pFormFocused == nullptr) {
        QMessageBox::warning(this, "Warning", "No image loaded. Please load a source image first.");
        return;
    }

    // Apply histogram equalization to the color image
    KImageColor img = _q_pFormFocused->ImageColor();
    img.HistogramEqualization();  // Apply equalization on the current image

    // Display the equalized image
    ImageForm* resultForm = new ImageForm(img, "Histogram Equalization Result", this);
    resultForm->show();
    _lImageForm.push_back(resultForm);

    // Update the UI to reflect the change
    UpdateUI();
}

void MainFrame::on_button_HM_clicked()
{
    // Check if the source image is loaded
    if (_q_pFormFocused == nullptr) {
        QMessageBox::warning(this, "Warning", "No source image loaded. Please load the source image first.");
        return;
    }

    // Check if a reference (target) image is loaded
    if (_q_pFormReference == nullptr) {
        QMessageBox::warning(this, "Warning", "No reference image loaded. Please load the target (reference) image.");
        return;
    }

    // Perform histogram matching between the source and target images
    KImageColor sourceImg = _q_pFormFocused->ImageColor();  // Source image
    KImageColor targetImg = _q_pFormReference->ImageColor();  // Reference/Target image

    sourceImg.HistogramMatching(targetImg);  // Perform histogram matching

    // Display the matched image
    ImageForm* resultForm = new ImageForm(sourceImg, "Histogram Matching Result", this);
    resultForm->show();
    _lImageForm.push_back(resultForm);

    // Update the UI to reflect the changes
    UpdateUI();
}

void MainFrame::on_button_Source_clicked()
{
    // Open a file dialog to select the source image
    QString sourceFile = QFileDialog::getOpenFileName(this, "Select Source Image", "", "Images (*.ppm *.png *.jpg *.bmp)");

    if (!sourceFile.isEmpty()) {
        // Load the source image and display it
        _q_pFormFocused = new ImageForm(sourceFile, "Source Image", this);
        _q_pFormFocused->show();
        _lImageForm.push_back(_q_pFormFocused);
    }
}

void MainFrame::on_button_REF_clicked()
{
    // Open a file dialog to select the reference (target) image
    QString refFile = QFileDialog::getOpenFileName(this, "Select Reference Image", "", "Images (*.ppm *.png *.jpg *.bmp)");

    if (!refFile.isEmpty()) {
        // Load the reference image and display it
        _q_pFormReference = new ImageForm(refFile, "Reference Image", this);
        _q_pFormReference->show();
        _lImageForm.push_back(_q_pFormReference);
    }
}


