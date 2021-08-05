#include "port.h"
#include "openfile.h"

Port::Port()
{
}

Port::Port(QPlainTextEdit *portinp)
{
    this->port_input = portinp;
}


