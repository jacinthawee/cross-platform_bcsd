
void list_md_fn(EVP_MD *param_1,undefined4 param_2,undefined4 param_3,BIO *param_4)

{
  int n;
  
  if (param_1 != (EVP_MD *)0x0) {
    n = EVP_MD_type(param_1);
    OBJ_nid2sn(n);
    BIO_printf(param_4,"%s\n");
    return;
  }
  BIO_printf(param_4,"%s => %s\n");
  return;
}

