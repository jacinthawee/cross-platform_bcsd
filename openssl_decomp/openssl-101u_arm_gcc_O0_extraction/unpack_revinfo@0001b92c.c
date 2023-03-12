
ASN1_OBJECT *
unpack_revinfo(ASN1_OBJECT **param_1,int *param_2,ASN1_OBJECT *param_3,ASN1_OBJECT **param_4,
              char *param_5)

{
  ASN1_OBJECT *__s;
  ASN1_OBJECT *a;
  ASN1_OBJECT *s;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  ASN1_OBJECT *a_00;
  
  __s = (ASN1_OBJECT *)BUF_strdup(param_5);
  if (__s == (ASN1_OBJECT *)0x0) {
    BIO_printf(bio_err,"memory allocation failure\n");
    pAVar1 = __s;
    s = __s;
    a_00 = __s;
    goto joined_r0x0001bb34;
  }
  a = (ASN1_OBJECT *)strchr((char *)__s,0x2c);
  s = a;
  if (a != (ASN1_OBJECT *)0x0) {
    pAVar1 = (ASN1_OBJECT *)((int)&a->sn + 1);
    *(undefined *)&a->sn = 0;
    s = (ASN1_OBJECT *)strchr((char *)pAVar1,0x2c);
    a = pAVar1;
    if (s != (ASN1_OBJECT *)0x0) {
      *(undefined *)&s->sn = 0;
      s = (ASN1_OBJECT *)((int)&s->sn + 1);
    }
  }
  if (param_1 != (ASN1_OBJECT **)0x0) {
    pAVar1 = (ASN1_OBJECT *)ASN1_UTCTIME_new();
    *param_1 = pAVar1;
    if (pAVar1 == (ASN1_OBJECT *)0x0) {
      BIO_printf(bio_err,"memory allocation failure\n");
      s = pAVar1;
      a_00 = pAVar1;
    }
    else {
      pAVar1 = (ASN1_OBJECT *)ASN1_UTCTIME_set_string((ASN1_UTCTIME *)pAVar1,(char *)__s);
      if (pAVar1 != (ASN1_OBJECT *)0x0) goto LAB_0001b98c;
      BIO_printf(bio_err,"invalid revocation date %s\n",__s);
      s = pAVar1;
      a_00 = pAVar1;
    }
    goto LAB_0001ba8c;
  }
LAB_0001b98c:
  if (a == (ASN1_OBJECT *)0x0) {
    iVar2 = -1;
    a_00 = a;
    goto LAB_0001bae2;
  }
  iVar2 = strcasecmp((char *)a,"unspecified");
  pAVar1 = s;
  if (iVar2 == 0) {
LAB_0001bb3c:
    if (1 < iVar2 - 9U) {
      a = (ASN1_OBJECT *)0x0;
      a_00 = (ASN1_OBJECT *)0x0;
      goto LAB_0001bae2;
    }
    if (s == (ASN1_OBJECT *)0x0) {
      BIO_printf(bio_err,"missing compromised time\n");
      a_00 = s;
    }
    else {
      pAVar1 = (ASN1_OBJECT *)ASN1_GENERALIZEDTIME_new();
      if (pAVar1 == (ASN1_OBJECT *)0x0) {
        BIO_printf(bio_err,"memory allocation failure\n");
        s = pAVar1;
        a_00 = pAVar1;
      }
      else {
        a_00 = (ASN1_OBJECT *)
               ASN1_GENERALIZEDTIME_set_string((ASN1_GENERALIZEDTIME *)pAVar1,(char *)s);
        if (a_00 != (ASN1_OBJECT *)0x0) {
          if (iVar2 == 9) {
            iVar2 = 1;
          }
          else {
            iVar2 = 2;
          }
          a = pAVar1;
          a_00 = (ASN1_OBJECT *)0x0;
          goto LAB_0001bae2;
        }
        BIO_printf(bio_err,"invalid compromised time %s\n",s);
        s = a_00;
      }
    }
  }
  else {
    iVar2 = strcasecmp((char *)a,"keyCompromise");
    if (iVar2 == 0) {
      iVar2 = 1;
      goto LAB_0001bb3c;
    }
    iVar2 = strcasecmp((char *)a,"CACompromise");
    if (iVar2 == 0) {
      iVar2 = 2;
      goto LAB_0001bb3c;
    }
    iVar2 = strcasecmp((char *)a,"affiliationChanged");
    if (iVar2 == 0) {
      iVar2 = 3;
      goto LAB_0001bb3c;
    }
    iVar2 = strcasecmp((char *)a,"superseded");
    if (iVar2 == 0) {
      iVar2 = 4;
      goto LAB_0001bb3c;
    }
    iVar2 = strcasecmp((char *)a,"cessationOfOperation");
    if (iVar2 == 0) {
      iVar2 = 5;
      goto LAB_0001bb3c;
    }
    iVar2 = strcasecmp((char *)a,"certificateHold");
    if (iVar2 == 0) {
      iVar2 = 6;
      goto LAB_0001bb3c;
    }
    a_00 = (ASN1_OBJECT *)strcasecmp((char *)a,"removeFromCRL");
    if (a_00 != (ASN1_OBJECT *)0x0) {
      iVar2 = strcasecmp((char *)a,"holdInstruction");
      if (iVar2 != 0) {
        iVar2 = strcasecmp((char *)a,"keyTime");
        if (iVar2 == 0) {
          iVar2 = 9;
        }
        else {
          iVar2 = strcasecmp((char *)a,"CAkeyTime");
          if (iVar2 != 0) {
            BIO_printf(bio_err,"invalid reason code %s\n",a);
            pAVar1 = (ASN1_OBJECT *)0x0;
            s = (ASN1_OBJECT *)0x0;
            a_00 = (ASN1_OBJECT *)0x0;
            goto LAB_0001ba8c;
          }
          iVar2 = 10;
        }
        goto LAB_0001bb3c;
      }
      if (s == (ASN1_OBJECT *)0x0) {
        BIO_printf(bio_err,"missing hold instruction\n");
        a_00 = s;
      }
      else {
        a_00 = OBJ_txt2obj((char *)s,0);
        if (a_00 != (ASN1_OBJECT *)0x0) {
          if (param_3 == (ASN1_OBJECT *)0x0) {
            iVar2 = 6;
            a = param_3;
          }
          else {
            param_3->sn = (char *)a_00;
            iVar2 = 6;
            a = (ASN1_OBJECT *)0x0;
          }
          goto LAB_0001bae2;
        }
        BIO_printf(bio_err,"invalid object identifier %s\n",s);
        pAVar1 = a_00;
        s = a_00;
      }
      goto LAB_0001ba8c;
    }
    iVar2 = 8;
    a = a_00;
LAB_0001bae2:
    if (param_2 != (int *)0x0) {
      *param_2 = iVar2;
    }
    pAVar1 = a;
    if (param_4 == (ASN1_OBJECT **)0x0) {
      ASN1_GENERALIZEDTIME_free((ASN1_GENERALIZEDTIME *)a);
      s = (ASN1_OBJECT *)0x1;
    }
    else {
      *param_4 = a;
      s = (ASN1_OBJECT *)0x1;
    }
  }
LAB_0001ba8c:
  CRYPTO_free(__s);
joined_r0x0001bb34:
  if (param_3 == (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(a_00);
  }
  if (param_4 != (ASN1_OBJECT **)0x0) {
    return s;
  }
  ASN1_GENERALIZEDTIME_free((ASN1_GENERALIZEDTIME *)pAVar1);
  return s;
}

