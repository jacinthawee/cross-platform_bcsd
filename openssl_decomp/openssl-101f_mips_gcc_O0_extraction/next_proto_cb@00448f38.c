
undefined4
next_proto_cb(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5,
             undefined4 *param_6)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (c_quiet == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"Protocols advertised by server: ");
    if (param_5 != 0) {
      uVar2 = 0;
      while( true ) {
        (*(code *)PTR_BIO_write_006a7f14)(bio_c_out,param_4 + uVar2 + 1,*(byte *)(param_4 + uVar2));
        uVar2 = uVar2 + *(byte *)(param_4 + uVar2) + 1;
        if (param_5 <= uVar2) break;
        if (uVar2 != 0) {
          (*(code *)PTR_BIO_write_006a7f14)(bio_c_out,", ",2);
        }
      }
    }
    (*(code *)PTR_BIO_write_006a7f14)(bio_c_out,"\n",1);
  }
  uVar1 = (*(code *)PTR_SSL_select_next_proto_006a8a50)
                    (param_2,param_3,param_4,param_5,*param_6,*(undefined2 *)(param_6 + 1));
  param_6[2] = uVar1;
  return 0;
}

