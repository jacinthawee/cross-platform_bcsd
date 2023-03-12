
int GENERAL_NAME_print(BIO *out,GENERAL_NAME *gen)

{
  stack_st_X509_NAME_ENTRY *psVar1;
  BUF_MEM *pBVar2;
  size_t *psVar3;
  BUF_MEM *pBVar4;
  
  if ((uint)gen->type < 9) {
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
    case 8:
      BIO_printf(out,"Registered ID");
      i2a_ASN1_OBJECT(out,(gen->d).registeredID);
      return 1;
    }
    pBVar4 = ((gen->d).directoryName)->bytes;
    psVar1 = ((gen->d).directoryName)->entries;
    if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_printf(out,"IP Address:%d.%d.%d.%d",(uint)*(byte *)&pBVar4->length,
                 (uint)*(byte *)((int)&pBVar4->length + 1),(uint)*(byte *)((int)&pBVar4->length + 2)
                 ,(uint)*(byte *)((int)&pBVar4->length + 3));
    }
    else if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x10) {
      pBVar2 = pBVar4 + 1;
      BIO_printf(out,"IP Address");
      do {
        psVar3 = &pBVar4->length;
        pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 2);
        BIO_printf(out,":%X",(uint)(ushort)(*(ushort *)psVar3 << 8 | *(ushort *)psVar3 >> 8));
      } while (pBVar4 != (BUF_MEM *)&pBVar2->data);
      BIO_puts(out,"\n");
    }
    else {
      BIO_printf(out,"IP Address:<invalid>");
    }
  }
  return 1;
}

