
void list_cipher_fn(EVP_CIPHER *param_1,undefined4 param_2,undefined4 param_3,BIO *param_4)

{
  int n;
  
  if (param_1 != (EVP_CIPHER *)0x0) {
    n = EVP_CIPHER_nid(param_1);
    OBJ_nid2sn(n);
    BIO_printf(param_4,"%s\n");
    return;
  }
  BIO_printf(param_4,"%s => %s\n");
  return;
}

