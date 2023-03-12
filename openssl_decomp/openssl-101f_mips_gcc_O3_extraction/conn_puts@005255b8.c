
int conn_puts(BIO *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int i;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = (*(code *)PTR_strlen_006aab30)(param_2);
                    /* WARNING: Load size is inaccurate */
  if ((*param_1->ptr == 6) || (i = conn_state(param_1), 0 < i)) {
    puVar2 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
    *puVar2 = 0;
    i = (*(code *)PTR_write_006aab28)(param_1->num,param_2,uVar1);
    BIO_clear_flags(param_1,0xf);
    if ((i < 1) && (iVar3 = BIO_sock_should_retry(i), iVar3 != 0)) {
      BIO_set_flags(param_1,10);
    }
  }
  return i;
}

