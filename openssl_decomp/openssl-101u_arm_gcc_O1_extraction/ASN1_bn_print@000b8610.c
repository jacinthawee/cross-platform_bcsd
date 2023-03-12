
int ASN1_bn_print(BIO *bp,char *number,BIGNUM *num,uchar *buf,int off)

{
  byte *pbVar1;
  uchar *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  
  if (num == (BIGNUM *)0x0) {
    return 1;
  }
  pcVar8 = "";
  if (num->neg != 0) {
    pcVar8 = "-";
  }
  iVar3 = BIO_indent(bp,off,0x80);
  if (iVar3 == 0) {
    return 0;
  }
  if (num->top == 0) {
    iVar3 = BIO_printf(bp,"%s 0\n",number);
    if (iVar3 < 1) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    iVar3 = BN_num_bits(num);
    if (0x20 < iVar3) {
      pcVar6 = " (Negative)";
      if (*pcVar8 != '-') {
        pcVar6 = "";
      }
      *buf = '\0';
      iVar3 = BIO_printf(bp,"%s%s",number,pcVar6);
      if (0 < iVar3) {
        iVar3 = BN_bn2bin(num,buf + 1);
        puVar2 = buf + 1;
        if ((char)buf[1] < '\0') {
          iVar3 = iVar3 + 1;
          puVar2 = buf;
        }
        if (iVar3 < 1) {
LAB_000b8780:
          iVar3 = BIO_write(bp,"\n",1);
          return (uint)(0 < iVar3);
        }
        iVar7 = 0;
        do {
          if (iVar7 == (iVar7 / 0xf) * 0xf) {
            iVar5 = BIO_puts(bp,"\n");
            if (iVar5 < 1) {
              return 0;
            }
            iVar5 = BIO_indent(bp,off + 4,0x80);
            if (iVar5 == 0) {
              return 0;
            }
          }
          pbVar1 = puVar2 + iVar7;
          iVar7 = iVar7 + 1;
          if (iVar7 == iVar3) {
            iVar3 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,"");
            if (iVar3 < 1) {
              return 0;
            }
            goto LAB_000b8780;
          }
          iVar5 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,":");
        } while (0 < iVar5);
      }
      return 0;
    }
    iVar3 = BIO_printf(bp,"%s %s%lu (%s0x%lx)\n",number,pcVar8,*num->d,pcVar8,*num->d);
    uVar4 = (uint)(0 < iVar3);
  }
  return uVar4;
}

