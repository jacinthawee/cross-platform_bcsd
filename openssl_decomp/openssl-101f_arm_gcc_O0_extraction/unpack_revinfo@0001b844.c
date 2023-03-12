
ASN1_OBJECT *
unpack_revinfo(ASN1_UTCTIME **param_1,int *param_2,ASN1_OBJECT *param_3,ASN1_OBJECT **param_4,
              char *param_5)

{
  char *__s;
  ASN1_OBJECT *a;
  ASN1_OBJECT *s;
  ASN1_UTCTIME *s_00;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  
  __s = BUF_strdup(param_5);
  a = (ASN1_OBJECT *)strchr(__s,0x2c);
  s = a;
  if (a != (ASN1_OBJECT *)0x0) {
    pAVar1 = (ASN1_OBJECT *)((int)&a->sn + 1);
    *(char *)&a->sn = '\0';
    s = (ASN1_OBJECT *)strchr((char *)pAVar1,0x2c);
    a = pAVar1;
    if (s != (ASN1_OBJECT *)0x0) {
      *(char *)&s->sn = '\0';
      s = (ASN1_OBJECT *)((int)&s->sn + 1);
    }
  }
  if (param_1 != (ASN1_UTCTIME **)0x0) {
    s_00 = ASN1_UTCTIME_new();
    *param_1 = s_00;
    pAVar1 = (ASN1_OBJECT *)ASN1_UTCTIME_set_string(s_00,__s);
    if (pAVar1 == (ASN1_OBJECT *)0x0) {
      BIO_printf(bio_err,"invalid revocation date %s\n",__s);
      s = pAVar1;
      pAVar3 = pAVar1;
      goto LAB_0001b996;
    }
  }
  if (a == (ASN1_OBJECT *)0x0) {
    iVar2 = -1;
    pAVar3 = a;
    goto LAB_0001b9ee;
  }
  iVar2 = strcasecmp((char *)a,"unspecified");
  pAVar1 = s;
  if (iVar2 == 0) {
LAB_0001ba04:
    if (iVar2 - 9U < 2) {
      if (s == (ASN1_OBJECT *)0x0) {
        BIO_printf(bio_err,"missing compromised time\n");
        pAVar3 = s;
        goto LAB_0001b996;
      }
      pAVar1 = (ASN1_OBJECT *)ASN1_GENERALIZEDTIME_new();
      pAVar3 = (ASN1_OBJECT *)
               ASN1_GENERALIZEDTIME_set_string((ASN1_GENERALIZEDTIME *)pAVar1,(char *)s);
      if (pAVar3 == (ASN1_OBJECT *)0x0) {
        BIO_printf(bio_err,"invalid compromised time %s\n",s);
        s = pAVar3;
        goto LAB_0001b996;
      }
      if (iVar2 == 9) {
        iVar2 = 1;
      }
      else {
        iVar2 = 2;
      }
      a = pAVar1;
      pAVar3 = (ASN1_OBJECT *)0x0;
    }
    else {
      a = (ASN1_OBJECT *)0x0;
      pAVar3 = (ASN1_OBJECT *)0x0;
    }
  }
  else {
    iVar2 = strcasecmp((char *)a,"keyCompromise");
    if (iVar2 == 0) {
      iVar2 = 1;
      goto LAB_0001ba04;
    }
    iVar2 = strcasecmp((char *)a,"CACompromise");
    if (iVar2 == 0) {
      iVar2 = 2;
      goto LAB_0001ba04;
    }
    iVar2 = strcasecmp((char *)a,"affiliationChanged");
    if (iVar2 == 0) {
      iVar2 = 3;
      goto LAB_0001ba04;
    }
    iVar2 = strcasecmp((char *)a,"superseded");
    if (iVar2 == 0) {
      iVar2 = 4;
      goto LAB_0001ba04;
    }
    iVar2 = strcasecmp((char *)a,"cessationOfOperation");
    if (iVar2 == 0) {
      iVar2 = 5;
      goto LAB_0001ba04;
    }
    iVar2 = strcasecmp((char *)a,"certificateHold");
    if (iVar2 == 0) {
      iVar2 = 6;
      goto LAB_0001ba04;
    }
    pAVar3 = (ASN1_OBJECT *)strcasecmp((char *)a,"removeFromCRL");
    if (pAVar3 == (ASN1_OBJECT *)0x0) {
      iVar2 = 8;
      a = pAVar3;
    }
    else {
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
            pAVar3 = (ASN1_OBJECT *)0x0;
            goto LAB_0001b996;
          }
          iVar2 = 10;
        }
        goto LAB_0001ba04;
      }
      if (s == (ASN1_OBJECT *)0x0) {
        BIO_printf(bio_err,"missing hold instruction\n");
        pAVar3 = s;
        goto LAB_0001b996;
      }
      pAVar1 = OBJ_txt2obj((char *)s,0);
      pAVar3 = pAVar1;
      if (pAVar1 == (ASN1_OBJECT *)0x0) {
        BIO_printf(bio_err,"invalid object identifier %s\n",s);
        s = pAVar1;
        goto LAB_0001b996;
      }
      if (param_3 == (ASN1_OBJECT *)0x0) {
        iVar2 = 6;
        a = param_3;
      }
      else {
        param_3->sn = (char *)pAVar1;
        iVar2 = 6;
        a = (ASN1_OBJECT *)0x0;
      }
    }
  }
LAB_0001b9ee:
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
LAB_0001b996:
  if (__s != (char *)0x0) {
    CRYPTO_free(__s);
  }
  if (param_3 == (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(pAVar3);
  }
  if (param_4 == (ASN1_OBJECT **)0x0) {
    ASN1_GENERALIZEDTIME_free((ASN1_GENERALIZEDTIME *)pAVar1);
    return s;
  }
  return s;
}

