
int SMIME_crlf_copy(BIO *in,BIO *out,int flags)

{
  bool bVar1;
  BIO_METHOD *type;
  BIO *b;
  int iVar2;
  BIO *b_00;
  int iVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  char acStack_422 [1026];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_f_buffer();
  b = BIO_new(type);
  iVar2 = 0;
  if (b != (BIO *)0x0) {
    b_00 = BIO_push(b,out);
    if ((flags & 0x80U) == 0) {
      if ((flags & 1U) != 0) {
        BIO_printf(b_00,"Content-Type: text/plain\r\n\r\n");
      }
      while( true ) {
        iVar2 = BIO_gets(in,acStack_422 + 2,0x400);
        if (iVar2 < 1) break;
        pcVar4 = acStack_422 + iVar2;
        bVar1 = false;
LAB_081ced67:
        iVar3 = iVar2 + -1;
        if (pcVar4[1] == '\n') {
          if (iVar3 == 0) goto LAB_081cee19;
          bVar1 = true;
LAB_081ced61:
          pcVar4 = pcVar4 + -1;
          iVar2 = iVar3;
          goto LAB_081ced67;
        }
        if (pcVar4[1] == '\r') {
          if (iVar3 == 0) goto LAB_081cee11;
          goto LAB_081ced61;
        }
        BIO_write(b_00,acStack_422 + 2,iVar2);
LAB_081cee11:
        if (bVar1) {
LAB_081cee19:
          BIO_write(b_00,"\r\n",2);
        }
      }
    }
    else {
      while( true ) {
        iVar2 = BIO_read(in,acStack_422 + 2,0x400);
        if (iVar2 < 1) break;
        BIO_write(b_00,acStack_422 + 2,iVar2);
      }
    }
    BIO_ctrl(b_00,0xb,0,(void *)0x0);
    BIO_pop(b_00);
    BIO_free(b);
    iVar2 = 1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

