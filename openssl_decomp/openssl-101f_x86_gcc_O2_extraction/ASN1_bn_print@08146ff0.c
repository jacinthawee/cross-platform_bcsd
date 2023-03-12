
int ASN1_bn_print(BIO *bp,char *number,BIGNUM *num,uchar *buf,int off)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uchar *puVar6;
  int local_24;
  
  if (num == (BIGNUM *)0x0) {
    return 1;
  }
  pcVar4 = "";
  pcVar5 = "-";
  if (num->neg == 0) {
    pcVar5 = "";
  }
  iVar2 = BIO_indent(bp,off,0x80);
  if (iVar2 == 0) {
    return 0;
  }
  if (num->top == 0) {
    iVar2 = BIO_printf(bp,"%s 0\n",number);
  }
  else {
    iVar2 = BN_num_bits(num);
    if (0x20 < iVar2) {
      cVar1 = *pcVar5;
      *buf = '\0';
      if (cVar1 == '-') {
        pcVar4 = " (Negative)";
      }
      iVar2 = BIO_printf(bp,"%s%s",number,pcVar4);
      if (0 < iVar2) {
        local_24 = BN_bn2bin(num,buf + 1);
        puVar6 = buf + 1;
        if ((char)buf[1] < '\0') {
          local_24 = local_24 + 1;
          puVar6 = buf;
        }
        iVar2 = 0;
        if (local_24 < 1) {
LAB_081471d1:
          iVar2 = BIO_write(bp,&DAT_081f11d3,1);
          return (uint)(0 < iVar2);
        }
        do {
          if (iVar2 == (iVar2 / 0xf) * 0xf) {
            iVar3 = BIO_puts(bp,"\n");
            if (iVar3 < 1) {
              return 0;
            }
            iVar3 = BIO_indent(bp,off + 4,0x80);
            if (iVar3 == 0) {
              return 0;
            }
          }
          if (local_24 == iVar2 + 1) {
            iVar2 = BIO_printf(bp,"%02x%s",(uint)puVar6[iVar2],&DAT_081ec74a);
            if (iVar2 < 1) {
              return 0;
            }
            goto LAB_081471d1;
          }
          iVar3 = BIO_printf(bp,"%02x%s",(uint)puVar6[iVar2],":");
          iVar2 = iVar2 + 1;
        } while (0 < iVar3);
      }
      return 0;
    }
    iVar2 = BIO_printf(bp,"%s %s%lu (%s0x%lx)\n",number,pcVar5,*num->d,pcVar5,*num->d);
  }
  return (uint)(0 < iVar2);
}

