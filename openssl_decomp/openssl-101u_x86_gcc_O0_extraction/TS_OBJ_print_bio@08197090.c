
undefined4 TS_OBJ_print_bio(BIO *param_1,ASN1_OBJECT *param_2)

{
  int in_GS_OFFSET;
  char local_90 [128];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  OBJ_obj2txt(local_90,0x80,param_2,0);
  BIO_printf(param_1,"%s\n",local_90);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

