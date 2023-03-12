
stack_st_CONF_VALUE *
i2v_GENERAL_NAME(X509V3_EXT_METHOD *method,GENERAL_NAME *gen,stack_st_CONF_VALUE *ret)

{
  BUF_MEM *pBVar1;
  stack_st_X509_NAME_ENTRY *psVar2;
  ushort *puVar3;
  ushort *puVar4;
  int in_GS_OFFSET;
  stack_st_CONF_VALUE *local_130 [2];
  char local_125 [5];
  char local_120 [256];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_130[0] = ret;
  if ((uint)gen->type < 9) {
    switch(gen->type) {
    case 0:
      X509V3_add_value("othername","<unsupported>",local_130);
      break;
    case 1:
      X509V3_add_value_uchar("email",((gen->d).rfc822Name)->data,local_130);
      break;
    case 2:
      X509V3_add_value_uchar("DNS",((gen->d).rfc822Name)->data,local_130);
      break;
    case 3:
      X509V3_add_value("X400Name","<unsupported>",local_130);
      break;
    case 4:
      X509_NAME_oneline((gen->d).directoryName,local_120,0x100);
      X509V3_add_value("DirName",local_120,local_130);
      break;
    case 5:
      X509V3_add_value("EdiPartyName","<unsupported>",local_130);
      break;
    case 6:
      X509V3_add_value_uchar("URI",((gen->d).rfc822Name)->data,local_130);
      break;
    case 7:
      pBVar1 = ((gen->d).directoryName)->bytes;
      psVar2 = ((gen->d).directoryName)->entries;
      if (psVar2 == (stack_st_X509_NAME_ENTRY *)0x4) {
        BIO_snprintf(local_120,0x100,"%d.%d.%d.%d",(uint)*(byte *)&pBVar1->length,
                     (uint)*(byte *)((int)&pBVar1->length + 1),
                     (uint)*(byte *)((int)&pBVar1->length + 2),
                     (uint)*(byte *)((int)&pBVar1->length + 3));
      }
      else {
        if (psVar2 != (stack_st_X509_NAME_ENTRY *)0x10) {
          X509V3_add_value("IP Address","<invalid>",local_130);
          break;
        }
        local_120[0] = '\0';
        BIO_snprintf(local_125,5,"%X",
                     (uint)(ushort)(*(ushort *)&pBVar1->length << 8 |
                                   *(ushort *)&pBVar1->length >> 8));
        __strcat_chk(local_120,local_125,0x100);
        puVar3 = (ushort *)((int)&pBVar1->length + 2);
        do {
          puVar4 = puVar3 + 1;
          __strcat_chk(local_120,":",0x100);
          BIO_snprintf(local_125,5,"%X",(uint)(ushort)(*puVar3 << 8 | *puVar3 >> 8));
          __strcat_chk(local_120,local_125,0x100);
          puVar3 = puVar4;
        } while ((char **)puVar4 != &pBVar1[1].data);
      }
      X509V3_add_value("IP Address",local_120,local_130);
      break;
    case 8:
      i2t_ASN1_OBJECT(local_120,0x100,(gen->d).registeredID);
      X509V3_add_value("Registered ID",local_120,local_130);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_130[0];
}

