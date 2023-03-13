
undefined4 __regparm3
parse_bags_constprop_1(_STACK *param_1_00,char *param_2,EVP_PKEY **param_3,_STACK *param_1)

{
  int iVar1;
  PKCS12_SAFEBAG *bag;
  ASN1_TYPE *pAVar2;
  EVP_PKEY *pEVar3;
  undefined4 uVar4;
  X509 *x;
  PKCS8_PRIV_KEY_INFO *p8;
  int iVar5;
  ASN1_STRING *pAVar6;
  int in_GS_OFFSET;
  ASN1_STRING *local_3c;
  uchar *local_24;
  int local_20;
  
  iVar5 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    iVar1 = sk_num(param_1_00);
    if (iVar1 <= iVar5) {
      uVar4 = 1;
LAB_08182585:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return uVar4;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    bag = (PKCS12_SAFEBAG *)sk_value(param_1_00,iVar5);
    pAVar2 = PKCS12_get_attr_gen(bag->attrib,0x9c);
    if (pAVar2 == (ASN1_TYPE *)0x0) {
      local_3c = (ASN1_STRING *)0x0;
    }
    else {
      local_3c = (pAVar2->value).asn1_string;
    }
    pAVar2 = PKCS12_get_attr_gen(bag->attrib,0x9d);
    if (pAVar2 == (ASN1_TYPE *)0x0) {
      pAVar6 = (ASN1_STRING *)0x0;
    }
    else {
      pAVar6 = (pAVar2->value).asn1_string;
    }
    iVar1 = OBJ_obj2nid(bag->type);
    if (iVar1 == 0x97) {
      if ((param_3 != (EVP_PKEY **)0x0) && (*param_3 == (EVP_PKEY *)0x0)) {
        p8 = PKCS12_decrypt_skey(bag,param_2,-1);
        if (p8 == (PKCS8_PRIV_KEY_INFO *)0x0) {
LAB_08182448:
          uVar4 = 0;
          goto LAB_08182585;
        }
        pEVar3 = EVP_PKCS82PKEY(p8);
        *param_3 = pEVar3;
        PKCS8_PRIV_KEY_INFO_free(p8);
        if (*param_3 == (EVP_PKEY *)0x0) {
          uVar4 = 0;
          goto LAB_08182585;
        }
      }
    }
    else if (iVar1 < 0x98) {
      if (((iVar1 == 0x96) && (param_3 != (EVP_PKEY **)0x0)) && (*param_3 == (EVP_PKEY *)0x0)) {
        pEVar3 = EVP_PKCS82PKEY((PKCS8_PRIV_KEY_INFO *)(bag->value).bag);
        *param_3 = pEVar3;
joined_r0x0818237e:
        if (pEVar3 == (EVP_PKEY *)0x0) goto LAB_08182448;
      }
    }
    else if (iVar1 == 0x98) {
      iVar1 = OBJ_obj2nid(((bag->value).bag)->type);
      if (iVar1 == 0x9e) {
        x = PKCS12_certbag2x509(bag);
        if (x == (X509 *)0x0) goto LAB_08182448;
        if ((pAVar6 == (ASN1_STRING *)0x0) ||
           (iVar1 = X509_keyid_set1(x,pAVar6->data,pAVar6->length), iVar1 != 0)) {
          if ((local_3c != (ASN1_STRING *)0x0) &&
             (iVar1 = ASN1_STRING_to_UTF8(&local_24,local_3c), -1 < iVar1)) {
            iVar1 = X509_alias_set1(x,local_24,iVar1);
            CRYPTO_free(local_24);
            if (iVar1 == 0) goto LAB_081824eb;
          }
          iVar1 = sk_push(param_1,x);
          if (iVar1 != 0) goto LAB_08182388;
        }
LAB_081824eb:
        X509_free(x);
        uVar4 = 0;
        goto LAB_08182585;
      }
    }
    else if (iVar1 == 0x9b) {
      pEVar3 = (EVP_PKEY *)parse_bags_constprop_1(param_1);
      goto joined_r0x0818237e;
    }
LAB_08182388:
    iVar5 = iVar5 + 1;
  } while( true );
}

