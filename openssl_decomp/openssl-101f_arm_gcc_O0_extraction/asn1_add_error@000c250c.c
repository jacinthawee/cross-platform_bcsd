
void asn1_add_error(uchar *address,int offset)

{
  char acStack_3c [16];
  char acStack_2c [16];
  int local_1c;
  
  local_1c = __TMC_END__;
  BIO_snprintf(acStack_3c,0xd,"%lu",address);
  BIO_snprintf(acStack_2c,0xd,"%d",offset);
  ERR_add_error_data(4,"address=",acStack_3c," offset=",acStack_2c);
  if (local_1c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

