
int ssl3_write_pending(SSL *param_1,int param_2,uchar *param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uchar *puVar4;
  ulong uVar5;
  BIO *b;
  int iVar6;
  ssl3_state_st *psVar7;
  bool bVar8;
  
  psVar7 = param_1->s3;
  if ((param_4 < psVar7->wpend_tot) ||
     (((psVar7->wpend_buf != param_3 && (-1 < (int)(param_1->options << 0x1e))) ||
      (psVar7->wpend_type != param_2)))) {
    ERR_put_error(0x14,0x9f,0x7f,"s3_pkt.c",0x367);
    return -1;
  }
  piVar2 = __errno_location();
  while( true ) {
    b = param_1->wbio;
    *piVar2 = 0;
    if (b == (BIO *)0x0) break;
    iVar6 = (psVar7->wbuf).offset;
    puVar4 = (psVar7->wbuf).buf;
    iVar3 = (psVar7->wbuf).left;
    param_1->rwstate = 2;
    iVar3 = BIO_write(b,puVar4 + iVar6,iVar3);
    iVar6 = (psVar7->wbuf).left;
    if (iVar3 == iVar6) goto LAB_00050ae0;
    if (iVar3 < 1) goto LAB_00050ac4;
    (psVar7->wbuf).left = iVar6 - iVar3;
    (psVar7->wbuf).offset = iVar3 + (psVar7->wbuf).offset;
  }
  ERR_put_error(0x14,0x9f,0x80,"s3_pkt.c",0x377);
  iVar3 = (psVar7->wbuf).left;
  if (iVar3 != -1) {
    iVar3 = -1;
LAB_00050ac4:
    iVar6 = param_1->version;
    bVar8 = iVar6 == 0xfeff;
    bVar1 = iVar6 == 0x100;
    if (bVar8 || bVar1) {
      iVar6 = 0;
    }
    if (bVar8 || bVar1) {
      (psVar7->wbuf).left = iVar6;
    }
    return iVar3;
  }
LAB_00050ae0:
  uVar5 = param_1->options;
  (psVar7->wbuf).left = 0;
  (psVar7->wbuf).offset = (psVar7->wbuf).offset + iVar3;
  if ((((int)(uVar5 << 0x1b) < 0) && (iVar3 = SSL_version(param_1), iVar3 != 0xfeff)) &&
     (iVar3 = SSL_version(param_1), iVar3 != 0x100)) {
    ssl3_release_write_buffer(param_1);
  }
  param_1->rwstate = 1;
  return param_1->s3->wpend_ret;
}

