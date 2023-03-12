
char * make_revocation_str(int param_1,char *param_2)

{
  ASN1_OBJECT *a;
  ASN1_TIME *a_00;
  size_t sVar1;
  char *dst;
  int iVar2;
  size_t sVar3;
  char *__s;
  
  switch(param_1) {
  case 1:
    iVar2 = strcasecmp(param_2,"unspecified");
    if (iVar2 == 0) {
      __s = "unspecified";
    }
    else {
      iVar2 = strcasecmp(param_2,"keyCompromise");
      if (iVar2 == 0) {
        __s = "keyCompromise";
      }
      else {
        iVar2 = strcasecmp(param_2,"CACompromise");
        if (iVar2 == 0) {
          __s = "CACompromise";
        }
        else {
          iVar2 = strcasecmp(param_2,"affiliationChanged");
          if (iVar2 == 0) {
            __s = "affiliationChanged";
          }
          else {
            iVar2 = strcasecmp(param_2,"superseded");
            if (iVar2 == 0) {
              __s = "superseded";
            }
            else {
              iVar2 = strcasecmp(param_2,"cessationOfOperation");
              if (iVar2 == 0) {
                __s = "cessationOfOperation";
              }
              else {
                iVar2 = strcasecmp(param_2,"certificateHold");
                if (iVar2 == 0) {
                  __s = "certificateHold";
                }
                else {
                  iVar2 = strcasecmp(param_2,"removeFromCRL");
                  if (iVar2 != 0) {
                    BIO_printf(bio_err,"Unknown CRL reason %s\n",param_2);
                    return (char *)0x0;
                  }
                  __s = "removeFromCRL";
                }
              }
            }
          }
        }
      }
    }
    param_2 = (char *)0x0;
    break;
  case 2:
    a = OBJ_txt2obj(param_2,0);
    ASN1_OBJECT_free(a);
    __s = "holdInstruction";
    if (a == (ASN1_OBJECT *)0x0) {
      BIO_printf(bio_err,"Invalid object identifier %s\n",param_2);
      return (char *)0x0;
    }
    break;
  case 3:
  case 4:
    iVar2 = ASN1_GENERALIZEDTIME_set_string((ASN1_GENERALIZEDTIME *)0x0,param_2);
    if (iVar2 == 0) {
      BIO_printf(bio_err,"Invalid time format %s. Need YYYYMMDDHHMMSSZ\n",param_2);
      return (char *)0x0;
    }
    __s = "CAkeyTime";
    if (param_1 == 3) {
      __s = "keyTime";
    }
    break;
  default:
    param_2 = (char *)0x0;
    __s = param_2;
  }
  a_00 = X509_gmtime_adj((ASN1_TIME *)0x0,0);
  if (a_00 != (ASN1_TIME *)0x0) {
    iVar2 = a_00->length;
    sVar3 = iVar2 + 1;
    if (__s != (char *)0x0) {
      sVar3 = strlen(__s);
      sVar3 = iVar2 + 2 + sVar3;
    }
    if (param_2 != (char *)0x0) {
      sVar1 = strlen(param_2);
      sVar3 = sVar3 + 1 + sVar1;
    }
    dst = (char *)CRYPTO_malloc(sVar3,"ca.c",0xa6e);
    if (dst != (char *)0x0) {
      BUF_strlcpy(dst,(char *)a_00->data,sVar3);
      if (__s != (char *)0x0) {
        BUF_strlcat(dst,",",sVar3);
        BUF_strlcat(dst,__s,sVar3);
      }
      if (param_2 != (char *)0x0) {
        BUF_strlcat(dst,",",sVar3);
        BUF_strlcat(dst,param_2,sVar3);
      }
      ASN1_UTCTIME_free(a_00);
      return dst;
    }
  }
  return (char *)0x0;
}

