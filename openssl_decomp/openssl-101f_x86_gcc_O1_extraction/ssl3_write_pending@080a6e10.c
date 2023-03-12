
int ssl3_write_pending(SSL *param_1,int param_2,uchar *param_3,int param_4)

{
  int *piVar1;
  byte bVar2;
  ssl3_state_st *psVar3;
  BIO *b;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  psVar3 = param_1->s3;
  if ((psVar3->wpend_tot != param_4 && param_4 <= psVar3->wpend_tot) ||
     (((psVar3->wpend_buf != param_3 && ((*(byte *)&param_1->options & 2) == 0)) ||
      (psVar3->wpend_type != param_2)))) {
    ERR_put_error(0x14,0x9f,0x7f,"s3_pkt.c",0x367);
    return -1;
  }
  piVar4 = __errno_location();
  while( true ) {
    b = param_1->wbio;
    *piVar4 = 0;
    if (b == (BIO *)0x0) break;
    param_1->rwstate = 2;
    iVar5 = BIO_write(b,(psVar3->wbuf).buf + (psVar3->wbuf).offset,(psVar3->wbuf).left);
    iVar6 = (psVar3->wbuf).left;
    if (iVar5 == iVar6) goto LAB_080a6ee2;
    if (iVar5 < 1) goto LAB_080a6f1d;
    piVar1 = &(psVar3->wbuf).offset;
    *piVar1 = *piVar1 + iVar5;
    (psVar3->wbuf).left = iVar6 - iVar5;
  }
  ERR_put_error(0x14,0x9f,0x80,"s3_pkt.c",0x377);
  if ((psVar3->wbuf).left == -1) {
    iVar6 = -1;
LAB_080a6ee2:
    piVar4 = &(psVar3->wbuf).offset;
    *piVar4 = *piVar4 + iVar6;
    bVar2 = *(byte *)&param_1->options;
    (psVar3->wbuf).left = 0;
    if ((bVar2 & 0x10) != 0) {
      iVar6 = SSL_version(param_1);
      if (iVar6 != 0xfeff) {
        iVar6 = SSL_version(param_1);
        if (iVar6 != 0x100) {
          ssl3_release_write_buffer(param_1);
        }
      }
    }
    param_1->rwstate = 1;
    iVar5 = param_1->s3->wpend_ret;
  }
  else {
    iVar5 = -1;
LAB_080a6f1d:
    if ((param_1->version == 0xfeff) || (param_1->version == 0x100)) {
      (psVar3->wbuf).left = 0;
      return iVar5;
    }
  }
  return iVar5;
}

