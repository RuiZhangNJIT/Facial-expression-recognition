#include "cvgabor.h"

 CvGabor::CvGabor()
 {
	 }


 CvGabor::~CvGabor()
{
	 }



	
	 CvGabor::CvGabor(int iMu, int iNu)
	 {
	     double dSigma = 2 * PI;
	     F = sqrt(2.0);
	    Init(iMu, iNu, dSigma, F);
	 }

 CvGabor::CvGabor(int iMu, int iNu, double dSigma)
 {
	    F = sqrt(2.0);
	     Init(iMu, iNu, dSigma, F);
	 }

 CvGabor::CvGabor(int iMu, int iNu, double dSigma, double dF)
 {
	    Init(iMu, iNu, dSigma, dF);
	 }

 CvGabor::CvGabor(double dPhi, int iNu)
 {
	     Sigma = 2 * PI;
	     F = sqrt(2.0);
	     Init(dPhi, iNu, Sigma, F);
	 }

 CvGabor::CvGabor(double dPhi, int iNu, double dSigma)
 {
	     F = sqrt(2.0);
	     Init(dPhi, iNu, dSigma, F);
	 }

 CvGabor::CvGabor(double dPhi, int iNu, double dSigma, double dF)
 {
	     Init(dPhi, iNu, dSigma, dF);
	 }

 
	 void CvGabor::Init(int iMu, int iNu, double dSigma, double dF)
	 {
	     //Initilise the parameters
		     bInitialised = false;
	     bKernel = false;
	
		     Sigma = dSigma;
	     F = dF;
	
		     Kmax = PI / 2;
	
		     //Absolute value of K
		     K = Kmax / pow(F, (double)iNu);
	   Phi = PI*iMu / 8;
	     bInitialised = true;
	
		     Width = mask_width();
	    creat_kernel();
	 }

 
	 void CvGabor::Init(double dPhi, int iNu, double dSigma, double dF)
	 {
	
		     bInitialised = false;
	    bKernel = false;
	     Sigma = dSigma;
	     F = dF;
	
		     Kmax = PI / 2;
	
	     
	    K = Kmax / pow(F, (double)iNu);
        Phi = dPhi;
        bInitialised = true;
	
		     Width = mask_width();
	     creat_kernel();
	}


	
	 bool CvGabor::IsInit()
	 {
	     return bInitialised;
	 }

 bool CvGabor::IsKernelCreate()
 {
	     return bKernel;
 }

 
	 int CvGabor::mask_width()
	 {
	     int lWidth;
         if (IsInit() == false)
		     {
		         cerr << "Error: The Object has not been initilised in mask_width()!\n" << endl;
		         return 0;
		     }
	    else
		     {
		         //determine the width of Mask
			        double dModSigma = Sigma / K;
		        int dWidth = cvRound(dModSigma * 6 + 1);
		
			         //test whether dWidth is an odd.
			         if ((dWidth % 2) == 0)
			         {
			             lWidth = dWidth + 1;
			         }
		        else
			         {
			             lWidth = dWidth;
			         }
		       return lWidth;
		     }
	}

 
	int CvGabor::get_mask_width()
	 {
	   return Width;
	 }

 
	 void CvGabor::creat_kernel()
	 {
	
		     if (IsInit() == false)
		     {
		         cerr << "Error: The Object has not been initilised in creat_kernel()!" << endl;
		     }
	    else
		     {
		         Mat mReal(Width, Width, CV_32FC1);
		         Mat mImag(Width, Width, CV_32FC1);
		
			       
			       int x, y;
		       double dReal;
		        double dImag;
		      double dTemp1, dTemp2, dTemp3;
		
			       for (int i = 0; i < Width; i++)
			      {
			            for (int j = 0; j < Width; j++)
				          {
				              x = i - (Width - 1) / 2;
				              y = j - (Width - 1) / 2;
				              dTemp1 = (pow(K, 2) / pow(Sigma, 2))*exp(-(pow((double)x, 2) + pow((double)y, 2))*pow(K, 2) / (2 * pow(Sigma, 2)));
				             dTemp2 = cos(K*cos(Phi)*x + K*sin(Phi)*y) - exp(-(pow(Sigma, 2) / 2));
			                 dTemp3 = sin(K*cos(Phi)*x + K*sin(Phi)*y);
				             dReal = dTemp1*dTemp2;
				              dImag = dTemp1*dTemp3;
				
					              mReal.row(i).col(j) = dReal;
				              mImag.row(i).col(j) = dImag;
			       }
			    }
		        
			       bKernel = true;
		
			        mReal.copyTo(Real);
		      mImag.copyTo(Imag);
		    }
	 }


 
	 void CvGabor::get_image(int Type, Mat& image)
	 {
	    if (IsKernelCreate() == false)
		     {
		         cerr << "Error: the Gabor kernel has not been created in get_image()!" << endl;
		         return;
		     }
	    else
		     {
		         Mat re(Width, Width, CV_32FC1);
		         Mat im(Width, Width, CV_32FC1);
		         Mat temp;
		
			        switch (Type)
			         {
			        case 1:  //Real
				             temp = Real.clone();
				             normalize(temp, temp, 255.0, 0.0, NORM_MINMAX);
				            break;
				        case 2:  //Imag
					            temp = Imag.clone();
					             break;
					        case 3:  //Magnitude
						             re = Real.clone();
						             im = Imag.clone();
						
							            pow(re, 2, re);
						             pow(im, 2, im);
						             add(im, re, temp);
						             pow(temp, 0.5, temp);
						            break;
						         case 4:  //Phase
							             ///@todo
								            break;
							         }
		
			         convertScaleAbs(temp, image, 1, 0);
		     }
	 }

 
	 void CvGabor::get_matrix(int Type, Mat& matrix)
	 {
	     if (!IsKernelCreate())
		     {
		         cerr << "Error: the gabor kernel has not been created!" << endl;
		         return;
		     }
	   switch (Type)
		    {
		     case CV_GABOR_REAL:
			        matrix = Real.clone();
			       break;
			   case CV_GABOR_IMAG:
				         matrix = Imag.clone();
				         break;
				     case CV_GABOR_MAG:
					         break;
					     case CV_GABOR_PHASE:
						         break;
						     }
	 }

 
	void CvGabor::conv_img(Mat &src, Mat &dst, int Type)
	 {
	     Mat mat = src.clone();
	
		     Mat rmat(src.rows, src.cols, CV_32FC1);
	    Mat imat(src.rows, src.cols, CV_32FC1);
	
		     switch (Type)
		     {
		     case CV_GABOR_REAL:
			       filter2D(mat, mat, 1, Real, Point((Width - 1) / 2, (Width - 1) / 2));
			         break;
			
				     case CV_GABOR_IMAG:
					         filter2D(mat, mat, 1, Imag, Point((Width - 1) / 2, (Width - 1) / 2));
					         break;
					
						     case CV_GABOR_MAG:
							       /* Real Response */
								         filter2D(mat, rmat, 1, Real, Point((Width - 1) / 2, (Width - 1) / 2));
							
								         /* Imag Response */
								         filter2D(mat, imat, 1, Imag, Point((Width - 1) / 2, (Width - 1) / 2));
							
								         /* Magnitude response is the square root of the sum of the square of real response and imaginary response */
								         pow(rmat, 2, rmat);
							        pow(imat, 2, imat);
							         add(rmat, imat, mat);
							    //    pow(mat, 0.5, mat);
									 

							        break;
							
								     case CV_GABOR_PHASE:
									         break;
									     }
	
		 //    cvNormalize(mat, mat, 0, 255, CV_MINMAX, NULL);
		    mat.copyTo(dst);
	}