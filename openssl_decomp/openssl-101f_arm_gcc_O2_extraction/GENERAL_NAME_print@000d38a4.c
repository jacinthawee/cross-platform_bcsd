
int GENERAL_NAME_print(BIO *out,GENERAL_NAME *gen)

{
  BUF_MEM *pBVar1;
  undefined *puVar2;
  stack_st_X509_NAME_ENTRY *psVar3;
  char **ppcVar4;
  BUF_MEM *pBVar5;
  
  switch(gen->type) {
  case 0:
    BIO_printf(out,"othername:<unsupported>");
    return 1;
  case 1:
    BIO_printf(out,"email:%s",((gen->d).rfc822Name)->data);
    return 1;
  case 2:
    BIO_printf(out,"DNS:%s",((gen->d).rfc822Name)->data);
    return 1;
  case 3:
    BIO_printf(out,"X400Name:<unsupported>");
    return 1;
  case 4:
    BIO_printf(out,"DirName: ");
    X509_NAME_print_ex(out,(gen->d).directoryName,0,0x82031f);
    return 1;
  case 5:
    BIO_printf(out,"EdiPartyName:<unsupported>");
    return 1;
  case 6:
    BIO_printf(out,"URI:%s",((gen->d).rfc822Name)->data);
    return 1;
  case 7:
    psVar3 = ((gen->d).directoryName)->entries;
    pBVar5 = ((gen->d).directoryName)->bytes;
    if (psVar3 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_printf(out,"IP Address:%d.%d.%d.%d",(uint)*(byte *)&pBVar5->length,
                 (uint)*(byte *)((int)&pBVar5->length + 1),(uint)*(byte *)((int)&pBVar5->length + 2)
                 ,(uint)*(byte *)((int)&pBVar5->length + 3));
    }
    else if (psVar3 == (stack_st_X509_NAME_ENTRY *)0x10) {
      ppcVar4 = (char **)((int)&pBVar5->length + 2);
      BIO_printf(out,"IP Address");
      do {
        pBVar1 = (BUF_MEM *)((int)ppcVar4 + -2);
        puVar2 = (undefined *)((int)ppcVar4 + -1);
        ppcVar4 = (char **)((int)ppcVar4 + 2);
        BIO_printf(out,":%X",(uint)CONCAT11(*(undefined *)&pBVar1->length,*puVar2));
      } while (ppcVar4 != (char **)((int)&pBVar5[1].data + 2));
      BIO_puts(out,"\n");
    }
    else {
      BIO_printf(out,"IP Address:<invalid>");
    }
    break;
  case 8:
    BIO_printf(out,"Registered ID");
    i2a_ASN1_OBJECT(out,(gen->d).registeredID);
    return 1;
  }
  return 1;
}

