
int GENERAL_NAME_print(BIO *out,GENERAL_NAME *gen)

{
  stack_st_X509_NAME_ENTRY *psVar1;
  BUF_MEM *pBVar2;
  BUF_MEM *pBVar3;
  BUF_MEM *pBVar4;
  
  switch(gen->type) {
  case 0:
    (*(code *)PTR_BIO_printf_006a6e38)(out,"othername:<unsupported>");
    return 1;
  case 1:
    (*(code *)PTR_BIO_printf_006a6e38)(out,"email:%s",((gen->d).rfc822Name)->data);
    return 1;
  case 2:
    (*(code *)PTR_BIO_printf_006a6e38)(out,"DNS:%s",((gen->d).rfc822Name)->data);
    return 1;
  case 3:
    (*(code *)PTR_BIO_printf_006a6e38)(out,"X400Name:<unsupported>");
    return 1;
  case 4:
    (*(code *)PTR_BIO_printf_006a6e38)(out,"DirName: ");
    (*(code *)PTR_X509_NAME_print_ex_006a7bc4)(out,(gen->d).ptr,0,0x82031f);
    return 1;
  case 5:
    (*(code *)PTR_BIO_printf_006a6e38)(out,"EdiPartyName:<unsupported>");
    return 1;
  case 6:
    (*(code *)PTR_BIO_printf_006a6e38)(out,"URI:%s",((gen->d).rfc822Name)->data);
    return 1;
  case 7:
    break;
  case 8:
    (*(code *)PTR_BIO_printf_006a6e38)(out,"Registered ID");
    (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(out,(gen->d).ptr);
    return 1;
  default:
    return 1;
  }
  psVar1 = ((gen->d).directoryName)->entries;
  pBVar2 = ((gen->d).directoryName)->bytes;
  if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x4) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (out,"IP Address:%d.%d.%d.%d",*(undefined *)&pBVar2->length,
               *(undefined *)((int)&pBVar2->length + 1),*(undefined *)((int)&pBVar2->length + 2),
               *(undefined *)((int)&pBVar2->length + 3));
  }
  else if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x10) {
    (*(code *)PTR_BIO_printf_006a6e38)(out,"IP Address");
    pBVar3 = pBVar2;
    do {
      pBVar4 = (BUF_MEM *)((int)&pBVar3->length + 2);
      (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_0066e45c,*(undefined2 *)&pBVar3->length);
      pBVar3 = pBVar4;
    } while (pBVar4 != (BUF_MEM *)&pBVar2[1].data);
    (*(code *)PTR_BIO_puts_006a6f58)(out,"\n");
  }
  else {
    (*(code *)PTR_BIO_printf_006a6e38)(out,"IP Address:<invalid>");
  }
  return 1;
}

