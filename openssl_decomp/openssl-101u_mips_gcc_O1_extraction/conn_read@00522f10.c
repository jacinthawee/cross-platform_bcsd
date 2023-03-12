
int conn_read(BIO *param_1,int param_2,undefined4 param_3)

{
  int i;
  undefined4 *puVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  if (*param_1->ptr == 6) {
    i = 0;
  }
  else {
    i = conn_state(param_1,param_1->ptr);
    if (i < 1) {
      return i;
    }
  }
  if (param_2 != 0) {
    puVar1 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
    *puVar1 = 0;
    i = (*(code *)PTR_read_006a9b10)(param_1->num,param_2,param_3);
    BIO_clear_flags(param_1,0xf);
    if ((i < 1) && (iVar2 = BIO_sock_should_retry(i), iVar2 != 0)) {
      BIO_set_flags(param_1,9);
    }
  }
  return i;
}

