
void list_md_fn(EVP_MD *param_1,undefined4 param_2,undefined4 param_3,BIO *param_4)

{
  int n;
  char *format;
  
  if (param_1 == (EVP_MD *)0x0) {
    format = "%s => %s\n";
  }
  else {
    n = EVP_MD_type(param_1);
    OBJ_nid2sn(n);
    format = "%s\n";
  }
  BIO_vprintf(param_4,format,&stack0xfffffff8);
  return;
}

