
int X509_EXTENSION_get_critical(X509_EXTENSION *ex)

{
  if (ex != (X509_EXTENSION *)0x0) {
    return (uint)(0 < ex->critical);
  }
  return 0;
}

