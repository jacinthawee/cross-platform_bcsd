
int conn_write(BIO *param_1,undefined4 param_2,undefined4 param_3)

{
  int i;
  undefined4 *puVar1;
  int iVar2;
  
                    /* WARNING: Load size is inaccurate */
  if ((*param_1->ptr == 6) || (i = conn_state(param_1,param_1->ptr), 0 < i)) {
    puVar1 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
    *puVar1 = 0;
    i = (*(code *)PTR_write_006aab28)(param_1->num,param_2,param_3);
    BIO_clear_flags(param_1,0xf);
    if ((i < 1) && (iVar2 = BIO_sock_should_retry(i), iVar2 != 0)) {
      BIO_set_flags(param_1,10);
    }
  }
  return i;
}

