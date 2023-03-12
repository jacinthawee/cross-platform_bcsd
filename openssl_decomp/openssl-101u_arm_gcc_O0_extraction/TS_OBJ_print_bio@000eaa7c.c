
void TS_OBJ_print_bio(BIO *param_1,ASN1_OBJECT *param_2)

{
  char acStack_94 [128];
  int local_14;
  
  local_14 = __stack_chk_guard;
  OBJ_obj2txt(acStack_94,0x80,param_2,0);
  BIO_printf(param_1,"%s\n",acStack_94);
  if (local_14 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}

