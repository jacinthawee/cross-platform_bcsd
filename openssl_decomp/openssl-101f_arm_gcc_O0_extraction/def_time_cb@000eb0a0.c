
undefined4 def_time_cb(int param_1,undefined4 param_2,__time_t *param_3,__suseconds_t *param_4)

{
  int iVar1;
  undefined4 uVar2;
  ASN1_BIT_STRING *a;
  timeval local_18;
  
  iVar1 = gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  if (iVar1 == 0) {
    uVar2 = 1;
    *param_3 = local_18.tv_sec;
    *param_4 = local_18.tv_usec;
  }
  else {
    ERR_put_error(0x2f,0x6f,0x7a,"ts_rsp_sign.c",0x75);
    TS_RESP_CTX_set_status_info(param_1,2,"Time is not available.");
    iVar1 = TS_RESP_get_status_info(*(undefined4 *)(param_1 + 0x48));
    a = *(ASN1_BIT_STRING **)(iVar1 + 8);
    if (a == (ASN1_BIT_STRING *)0x0) {
      a = ASN1_BIT_STRING_new();
      *(ASN1_BIT_STRING **)(iVar1 + 8) = a;
      if (a == (ASN1_BIT_STRING *)0x0) goto LAB_000eb0fe;
    }
    iVar1 = ASN1_BIT_STRING_set_bit(a,0xe,1);
    if (iVar1 == 0) {
LAB_000eb0fe:
      ERR_put_error(0x2f,0x7c,0x41,"ts_rsp_sign.c",0x18b);
      return 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}

