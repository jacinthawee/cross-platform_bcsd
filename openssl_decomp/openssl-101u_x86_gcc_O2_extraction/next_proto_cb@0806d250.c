
undefined4
next_proto_cb(undefined4 param_1,uchar **param_2,uchar *param_3,uchar *param_4,uint param_5,
             uchar **param_6)

{
  uchar *puVar1;
  uint uVar2;
  
  if (c_quiet == 0) {
    BIO_printf(bio_c_out,"Protocols advertised by server: ");
    if (param_5 != 0) {
      uVar2 = 0;
      while( true ) {
        BIO_write(bio_c_out,param_4 + uVar2 + 1,(uint)param_4[uVar2]);
        uVar2 = uVar2 + 1 + (uint)param_4[uVar2];
        if (param_5 <= uVar2) break;
        if (uVar2 != 0) {
          BIO_write(bio_c_out,", ",2);
        }
      }
    }
    BIO_write(bio_c_out,&DAT_081f15cb,1);
  }
  puVar1 = (uchar *)SSL_select_next_proto
                              (param_2,param_3,param_4,param_5,*param_6,
                               (uint)*(ushort *)(param_6 + 1));
  param_6[2] = puVar1;
  return 0;
}

