
void asn1_add_error(uchar *address,int offset)

{
  int in_GS_OFFSET;
  char local_2a [13];
  char local_1d [13];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  BIO_snprintf(local_2a,0xd,"%lu",address);
  BIO_snprintf(local_1d,0xd,"%d",offset);
  ERR_add_error_data(4,"address=",local_2a," offset=",local_1d);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

