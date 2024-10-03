#include <fcgiapp.h>
#include <stdio.h>

int main()
{
	FCGX_Request req;

	FCGX_Init();
	FCGX_InitRequest(&req, 0, 0);

	while(FCGX_Accept_r(&req) == 0)
	{
		printf("Accepted\n");
		FCGX_FPrintF(req.out, "Content-type: text/html\r\n\r\n<h1>Hello, World!</h1>");
		FCGX_Finish_r(&req);
	}
	return 0;
}
