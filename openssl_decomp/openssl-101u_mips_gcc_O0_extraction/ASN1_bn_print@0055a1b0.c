
int ASN1_bn_print(BIO *bp,char *number,BIGNUM *num,uchar *buf,int off)

{
  char cVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  char *pcVar6;
  int iVar7;
  
  if (num == (BIGNUM *)0x0) {
    return 1;
  }
  if (num->neg == 0) {
    pcVar6 = "";
  }
  else {
    pcVar6 = "-";
  }
  iVar3 = (*(code *)PTR_BIO_indent_006a86ac)(bp,off,0x80);
  if (iVar3 == 0) {
    return 0;
  }
  if (num->top == 0) {
    iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%s 0\n",number);
  }
  else {
    iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(num);
    if (0x20 < iVar3) {
      cVar1 = *pcVar6;
      *buf = '\0';
      if (cVar1 == '-') {
        pcVar6 = " (Negative)";
      }
      else {
        pcVar6 = "";
      }
      iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%s%s",number,pcVar6);
      if (0 < iVar3) {
        iVar3 = (*(code *)PTR_BN_bn2bin_006a7200)(num,buf + 1);
        puVar5 = buf + 1;
        if ((char)buf[1] < '\0') {
          iVar3 = iVar3 + 1;
          puVar5 = buf;
        }
        if (iVar3 < 1) {
LAB_0055a450:
          iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
          return (uint)(0 < iVar3);
        }
        iVar7 = 0;
        do {
          if (iVar7 == (iVar7 / 0xf) * 0xf) {
            iVar4 = (*(code *)PTR_BIO_puts_006a6f58)(bp,"\n");
            if (iVar4 < 1) {
              return 0;
            }
            iVar4 = (*(code *)PTR_BIO_indent_006a86ac)(bp,off + 4,0x80);
            if (iVar4 == 0) {
              return 0;
            }
          }
          iVar7 = iVar7 + 1;
          uVar2 = *puVar5;
          if (iVar3 == iVar7) {
            iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%02x%s",uVar2,"");
            if (iVar3 < 1) {
              return 0;
            }
            goto LAB_0055a450;
          }
          puVar5 = puVar5 + 1;
          iVar4 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%02x%s",uVar2,":");
        } while (0 < iVar4);
      }
      return 0;
    }
    iVar3 = (*(code *)PTR_BIO_printf_006a6e38)
                      (bp,"%s %s%lu (%s0x%lx)\n",number,pcVar6,*num->d,pcVar6,*num->d);
  }
  return (uint)(0 < iVar3);
}

