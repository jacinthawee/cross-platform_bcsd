
char * make_revocation_str(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  ASN1_TIME *a;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  ASN1_OBJECT *a_00;
  byte bVar6;
  char *local_20;
  
  bVar6 = 0;
  if (param_1 == 2) {
    a_00 = OBJ_txt2obj(param_2,0);
    ASN1_OBJECT_free(a_00);
    if (a_00 == (ASN1_OBJECT *)0x0) {
      BIO_printf(bio_err,"Invalid object identifier %s\n",param_2);
      return (char *)0x0;
    }
    local_20 = "holdInstruction";
LAB_08057221:
    a = X509_gmtime_adj((ASN1_TIME *)0x0,0);
    if (a == (ASN1_TIME *)0x0) {
      return (char *)0x0;
    }
    sVar3 = strlen(local_20);
    sVar3 = sVar3 + 2 + a->length;
    if (param_2 == (char *)0x0) {
LAB_080574a5:
      pcVar5 = (char *)CRYPTO_malloc(sVar3,"ca.c",0xa6e);
      if (pcVar5 == (char *)0x0) {
        return (char *)0x0;
      }
      BUF_strlcpy(pcVar5,(char *)a->data,sVar3);
      if (local_20 == (char *)0x0) goto LAB_080572d6;
      param_2 = (char *)0x0;
    }
    else {
      sVar4 = strlen(param_2);
      sVar3 = sVar3 + 1 + sVar4;
      pcVar5 = (char *)CRYPTO_malloc(sVar3,"ca.c",0xa6e);
      if (pcVar5 == (char *)0x0) {
        return (char *)0x0;
      }
      BUF_strlcpy(pcVar5,(char *)a->data,sVar3);
    }
    BUF_strlcat(pcVar5,",",sVar3);
    BUF_strlcat(pcVar5,local_20,sVar3);
    if (param_2 != (char *)0x0) {
      BUF_strlcat(pcVar5,",",sVar3);
      BUF_strlcat(pcVar5,param_2,sVar3);
    }
  }
  else {
    if (param_1 < 3) {
      if (param_1 == 1) {
        iVar2 = strcasecmp(param_2,"unspecified");
        if (iVar2 == 0) {
          local_20 = "unspecified";
        }
        else {
          iVar2 = strcasecmp(param_2,"keyCompromise");
          if (iVar2 == 0) {
            local_20 = "keyCompromise";
          }
          else {
            iVar2 = strcasecmp(param_2,"CACompromise");
            if (iVar2 == 0) {
              local_20 = "CACompromise";
            }
            else {
              iVar2 = strcasecmp(param_2,"affiliationChanged");
              if (iVar2 == 0) {
                local_20 = "affiliationChanged";
              }
              else {
                iVar2 = strcasecmp(param_2,"superseded");
                if (iVar2 == 0) {
                  local_20 = "superseded";
                }
                else {
                  iVar2 = strcasecmp(param_2,"cessationOfOperation");
                  if (iVar2 == 0) {
                    local_20 = "cessationOfOperation";
                  }
                  else {
                    iVar2 = strcasecmp(param_2,"certificateHold");
                    if (iVar2 == 0) {
                      local_20 = "certificateHold";
                    }
                    else {
                      iVar2 = strcasecmp(param_2,"removeFromCRL");
                      if (iVar2 != 0) {
                        BIO_printf(bio_err,"Unknown CRL reason %s\n",param_2);
                        return (char *)0x0;
                      }
                      local_20 = "removeFromCRL";
                    }
                  }
                }
              }
            }
          }
        }
        a = X509_gmtime_adj((ASN1_TIME *)0x0,0);
        if (a == (ASN1_TIME *)0x0) {
          return (char *)0x0;
        }
        iVar2 = -1;
        pcVar5 = local_20;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + (uint)bVar6 * -2 + 1;
        } while (cVar1 != '\0');
        sVar3 = a->length - iVar2;
        goto LAB_080574a5;
      }
    }
    else if (param_1 < 5) {
      iVar2 = ASN1_GENERALIZEDTIME_set_string((ASN1_GENERALIZEDTIME *)0x0,param_2);
      if (iVar2 == 0) {
        BIO_printf(bio_err,"Invalid time format %s. Need YYYYMMDDHHMMSSZ\n",param_2);
        return (char *)0x0;
      }
      local_20 = "CAkeyTime";
      if (param_1 == 3) {
        local_20 = "keyTime";
      }
      goto LAB_08057221;
    }
    a = X509_gmtime_adj((ASN1_TIME *)0x0,0);
    if (a == (ASN1_TIME *)0x0) {
      return (char *)0x0;
    }
    sVar3 = a->length + 1;
    pcVar5 = (char *)CRYPTO_malloc(sVar3,"ca.c",0xa6e);
    if (pcVar5 == (char *)0x0) {
      return (char *)0x0;
    }
    BUF_strlcpy(pcVar5,(char *)a->data,sVar3);
  }
LAB_080572d6:
  ASN1_UTCTIME_free(a);
  return pcVar5;
}

