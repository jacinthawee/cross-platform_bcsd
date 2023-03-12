
stack_st_CONF_VALUE *
i2v_GENERAL_NAME(X509V3_EXT_METHOD *method,GENERAL_NAME *gen,stack_st_CONF_VALUE *ret)

{
  stack_st_X509_NAME_ENTRY *psVar1;
  char **ppcVar2;
  BUF_MEM *pBVar3;
  stack_st_CONF_VALUE *local_12c [2];
  char acStack_124 [8];
  char local_11c [256];
  int local_1c;
  
  local_1c = __TMC_END__;
  local_12c[0] = ret;
  switch(gen->type) {
  case 0:
    X509V3_add_value("othername","<unsupported>",local_12c);
    break;
  case 1:
    X509V3_add_value_uchar("email",((gen->d).rfc822Name)->data,local_12c);
    break;
  case 2:
    X509V3_add_value_uchar("DNS",((gen->d).rfc822Name)->data,local_12c);
    break;
  case 3:
    X509V3_add_value("X400Name","<unsupported>",local_12c);
    break;
  case 4:
    X509_NAME_oneline((gen->d).directoryName,local_11c,0x100);
    X509V3_add_value("DirName",local_11c,local_12c);
    break;
  case 5:
    X509V3_add_value("EdiPartyName","<unsupported>",local_12c);
    break;
  case 6:
    X509V3_add_value_uchar("URI",((gen->d).rfc822Name)->data,local_12c);
    break;
  case 7:
    psVar1 = ((gen->d).directoryName)->entries;
    pBVar3 = ((gen->d).directoryName)->bytes;
    if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_snprintf(local_11c,0x100,"%d.%d.%d.%d",(uint)*(byte *)&pBVar3->length,
                   (uint)*(byte *)((int)&pBVar3->length + 1),
                   (uint)*(byte *)((int)&pBVar3->length + 2),
                   (uint)*(byte *)((int)&pBVar3->length + 3));
    }
    else {
      if (psVar1 != (stack_st_X509_NAME_ENTRY *)0x10) {
        X509V3_add_value("IP Address","<invalid>",local_12c);
        break;
      }
      local_11c[0] = '\0';
      ppcVar2 = &pBVar3->data;
      BIO_snprintf(acStack_124,5,"%X",
                   (uint)CONCAT11(*(undefined *)&pBVar3->length,
                                  *(undefined *)((int)&pBVar3->length + 1)));
      __strcat_chk(local_11c,acStack_124,0x100);
      do {
        __strcat_chk(local_11c,":",0x100);
        BIO_snprintf(acStack_124,5,"%X",
                     (uint)CONCAT11(*(undefined *)((int)ppcVar2 + -2),
                                    *(undefined *)((int)ppcVar2 + -1)));
        ppcVar2 = (char **)((int)ppcVar2 + 2);
        __strcat_chk(local_11c,acStack_124,0x100);
      } while (ppcVar2 != (char **)((int)&pBVar3[1].data + 2));
    }
    X509V3_add_value("IP Address",local_11c,local_12c);
    break;
  case 8:
    i2t_ASN1_OBJECT(local_11c,0x100,(gen->d).registeredID);
    X509V3_add_value("Registered ID",local_11c,local_12c);
  }
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_12c[0];
}

