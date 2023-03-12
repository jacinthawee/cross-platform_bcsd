
undefined4 TS_OBJ_print_bio(BIO *param_1,ASN1_OBJECT *param_2)

{
  int len;
  int in_GS_OFFSET;
  char local_90 [128];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  len = OBJ_obj2txt(local_90,0x80,param_2,0);
  BIO_write(param_1,local_90,len);
  BIO_write(param_1,&DAT_081f11d3,1);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

