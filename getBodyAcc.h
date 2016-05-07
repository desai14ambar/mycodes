#ifndef getBodyAcc_h
#define getBodyAcc_h

class getBodyAcc
{
	public:
		getBodyAcc(float ax, float ay, float az, float ag1, float ag2, float ag3, float fac){
		accall[0] = ax;
		accall[1] = ay;
		accall[2] = az;

                alpha = ag1;
                beta  = ag2;
                gama  = ag3;
                
		factr = fac;
		};
		
		void readAcc(float * bodyacc);
		
		private:
			float accall[3];
			float factr;
                        float gbody[3];
                        float alpha;
                        float beta;
                        float gama;
                        const float g  = 9.8f; // m/s^2
                                               
};		


// below code to get acc in body frame
void getBodyAcc::readAcc(float * bodyacc) {
    
  alpha = alpha *M_PI/180;
  beta  = beta  *M_PI/180;
  gama  = gama  *M_PI/180;
  
  gbody[0] = g*( cos(alpha) * sin(beta) * cos(gama) + sin(alpha) * sin(gama) ) ;
  gbody[1] = g*( sin(alpha) * sin(beta) * cos(gama) - cos(alpha) * sin(gama) ) ;
  gbody[2] = g*( cos(beta)  * cos(gama) );

  bodyacc[0] = accall[0] /factr - gbody[0];
  bodyacc[1] = accall[1] /factr - gbody[1];
  bodyacc[2] = accall[2] /factr - gbody[2];

//  bodyacc[0] = alpha*accall[0];
//  bodyacc[1] = accall[1];
//  bodyacc[2] = accall[2];
//return (bodyacc);
}

#endif

