
void ssl_puts(BIO *param_1,char *param_2)

{
  size_t len;
  
  len = strlen(param_2);
  BIO_write(param_1,param_2,len);
  return;
}

