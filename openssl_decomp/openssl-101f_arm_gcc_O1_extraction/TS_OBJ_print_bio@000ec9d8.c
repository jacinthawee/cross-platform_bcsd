
void TS_OBJ_print_bio(BIO *param_1,ASN1_OBJECT *param_2)

{
  int len;
  char acStack_94 [128];
  int local_14;
  
  local_14 = __TMC_END__;
  len = OBJ_obj2txt(acStack_94,0x80,param_2,0);
  BIO_write(param_1,acStack_94,len);
  BIO_write(param_1,"\n",1);
  if (local_14 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}

