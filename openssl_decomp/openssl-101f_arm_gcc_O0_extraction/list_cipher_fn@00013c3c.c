
void list_cipher_fn(EVP_CIPHER *param_1,char *param_2,char *param_3,BIO *param_4)

{
  int n;
  char *pcVar1;
  
  if (param_1 != (EVP_CIPHER *)0x0) {
    n = EVP_CIPHER_nid(param_1);
    pcVar1 = OBJ_nid2sn(n);
    BIO_printf(param_4,"%s\n",pcVar1);
    return;
  }
  if (param_2 == (char *)0x0) {
    param_2 = "<undefined>";
  }
  pcVar1 = "<undefined>";
  if (param_3 != (char *)0x0) {
    pcVar1 = param_3;
  }
  BIO_printf(param_4,"%s => %s\n",param_2,pcVar1);
  return;
}

