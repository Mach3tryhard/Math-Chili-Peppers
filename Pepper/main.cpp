#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <cmath>
double pi = 3.14159265358979323846;  /* pi */
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

/* MATH CODE */

double F(double x)
{
    double rez = (int)255*pow(exp(1),pow(-exp(1),-1000*x));
    rez*=pow(abs(x),pow(exp(1),pow(-exp(1),1000*(x-1))));
    return rez;
}

double U(double s,double x,double y)
{
    double rez = cos(17*x) + sin(17 *s) *y + 2*sin(8*s);
    return rez;
}

double V(double s,double x,double y)
{
    double rez = cos(17*s)*y - sin(17*s)*x + 2*sin(9*s);
    return rez;
}

double W(double x,double y)
{
    double rez;
    for(int s=1;s<=40;s++)
    {
        double frac1=11/10;
        double frac2=19/20;
        double a = pow(cos(pow(frac1,s)*20*(cos(2*s)*x+sin(2*s)*y)+2*sin(s*5)),2);
        double b = pow(cos(pow(frac1,s)*20*(cos(2*s)*y-sin(2*s)*x)+2*sin(s*6)),2);
        rez+=pow(exp(1),pow(-exp(1),-2*a*b-frac2));
    }
    return rez;
}

double P(double s,double x,double y)
{
    double rez = 4* V(s,x,y) + pow(10,-1)*pow(cos(3*U(s,x,y) + 2*V(s,x,y) + cos(4*V(s,x,y)) +2),2);
    rez+= pow(10,-1)*pow(cos(9*U(s,x,y) - 2*V(s,x,y) + cos(6*V(s,x,y)) +1),2);
    rez+= pow(100,-1)*3*pow(cos(29*U(s,x,y) + 7*V(s,x,y) + cos(5*V(s,x,y) + 8*U(s,x,y)) +1),4);
    rez+= pow(100,-1)*pow(cos(79*U(s,x,y) - 23*V(s,x,y) + 2*cos(15*V(s,x,y) - 38*U(s,x,y)) +1),4);
    return rez;
}

double Q(double s,double x,double y)
{
    double rez = 2*U(s,x,y) + pow(10,-1)*pow(cos(3*V(s,x,y) + 2*U(s,x,y)+cos(3*U(s,x,y))+2),2);
    rez += pow(2,-1)*pow(exp(1),pow(-exp(1),100*cos(P(s,x,y)-pow(sin(U(s,x,y) + pi/4),6))));
    return rez;
}

double K(double v,double s,double x,double y)
{
    double frac1=7/10;
    double frac2=1/2;
    double frac3=97/100;
    double frac4=1/50;
    double frac5=23/50;
    double frac6=7/20;

    double a=pow(cos(4*V(s,x,y)+frac1*pow(cos(frac2*Q(s,x,y))+pi/4,30)),12)-frac3;
    double b=frac4*pow(cos(frac2*Q(s,x,y)+pi/4),16);
    double rez=pow(exp(1),pow(-exp(1),-v*a-b)*pow(-exp(1),40*(abs(pow(cos(frac2*Q(s,x,y)+pi/4),30)-frac5)-frac6)));
    return rez;
}

double L(double v,double s,double x,double y)
{
    double frac1=1/2;
    double frac2=4/5;
    double frac3=7/10;

    double a=abs(cos(P(s,x,y) - pow(sin(frac1*Q(s,x,y)+pi/4),6)));
    double rez=pow(exp(1),pow(-exp(1),-v*pow(a,10+9*sin(Q(s,x,y)))* pow(abs(cos(Q(s,x,y))),frac2) +frac3*v));
}

double J(double v,double s,double x,double y)
{
    double rez= 1 - (1-L(v,s,x,y))*(1-K(v,s,x,y));
    return rez;
}

double N(double s,double x,double y)
{
    double frac1=1/2;
    double franc2=4/5;
    double franc3=96/25;

    double a=abs(cos(P(s,x,y)-pow(sin(frac1*Q(s,x,y)+pi/4),6)));
    double rez=pow(exp(1),pow(-exp(1),-6*pow(a,10+9*sin(Q(s,x,y))) * pow(abs(cos(Q(s,x,y))),franc2) +franc3));///MAYBE WRONG
    return rez;
}

double B(double s,double x,double y)
{
    double a=1/2 * Q(s,x,y)+pi/4+1/20 * pow(cos(10*P(s,x,y)+cos(3*s)),4);
    double rez=pow(exp(1),pow(-exp(1),-100*(pow(cos(a),20)-1/10)));
    return rez;
}

double C(double s,double v,double x,double y)
{
    double a=abs(cos(P(s,x,y)) - pow(sin(1/2 * Q(s,x,y)+pi/2),6));
    double b=10+9*sin(Q(s,x,y));
    double c=pow(abs(Q(s,x,y)),4/5);
    double d=(30+10*cos(4*s))*(Q(s,x,y)+3/100 * cos(5*P(s,x,y)))+2*cos(17*Q(s,x,y)+P(s,x,y)+2)+cos(27*Q(s,x,y))-17*P(s,x,y)+2*cos(5*s);
    double rez=pow(exp(1),pow(-exp(1),-v*pow(a,b)*c*(1/10*cos(d)+9/10)+97/100*v-3/100*v*W(x,y)));
    return rez;
}

double R(double s,double x,double y)
{
    double a=(30+10*cos(4*s))*(Q(s,x,y)+pow(100,-1)*3*cos(5*P(s,x,y)))+2*cos(17*Q(s,x,y)+P(s,x,y)+2)+cos(27*Q(s,x,y)-17*P(s,x,y)+2)+2*cos(5*s);
    double rez=pow(exp(1),pow(-exp(1),-sin(a)));
    return rez;
}

double A(double v,double s,double x,double y)
{
    double rez=pow(10,-1)*(1-B(s,x,y))*(4*v*v - 16*v + 16+ pow(-1,s)*(11*v-5*v*v-2)+(5*v-3*v*v+2)*cos((7+v)*s)+pow(20,-1)*(40-s)*(6*C(20,s,x,y)+5*C(5,x,x,y)-2*R(s,x,y)));
    rez+=pow(10,-1)*(-9*v*v+13*v+10+cos((v+4)*s))*B(s,x,y)+pow(20,-1)*3*W(x,y);
    return rez;
}

double H(double v,double x,double y)
{
    double rez=0;
    for(int s=1;s<=70;s++)
    {
        double produs=1;
        for(int u=0;u<=s-1;u++)
        {
            produs*=(1-pow(exp(1),pow(-exp(1),-1000*(u-1/2)))*J(200,u,x,y))*(1-7/10*pow(exp(1),pow(-exp(1),-1000*(u-1/2)))*N(u,x,y));
        }
        rez+=J(200,s,x,y)*A(v,s,x,y)*J(2,s,x,y)*(2/5+3/5*J(20,s,x,y))*produs;
    }
    return rez;
}

void Calculate(HDC hdc)
{
    for(int m=1;m<=2000;m++)
    {
        for(int n=1;n<=1200;n++)
        {
            SetPixel(hdc, n, m, RGB(F(H(0,(m-1000)/600,(601-n)/600)), F(H(1,(m-1000)/600,(601-n)/600)), F(H(2,(m-1000)/600,(601-n)/600))));
        }
    }
}

/* END OF MY IMPLEMENTATION */

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           2000,                 /* The programs width */
           1200,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Set the pixel color after the window is created */
    HDC hdc = GetDC(hwnd);
    Calculate(hdc);
    ReleaseDC(hwnd, hdc);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
