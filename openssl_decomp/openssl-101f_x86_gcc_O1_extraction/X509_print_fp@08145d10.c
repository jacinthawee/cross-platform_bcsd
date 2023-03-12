
int X509_print_fp(FILE *bp,X509 *x)

{
  X509_CINF *pXVar1;
  X509_ALGOR *pXVar2;
  ASN1_UTCTIME *a;
  ASN1_GENERALIZEDTIME *a_00;
  BIO_METHOD *type;
  BIO *bp_00;
  int iVar3;
  long lVar4;
  ASN1_INTEGER *a_01;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  X509_NAME *pXVar8;
  EVP_PKEY_ASN1_METHOD *pEVar9;
  EVP_PKEY *pkey;
  undefined1 *puVar10;
  uint uVar11;
  int in_GS_OFFSET;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 == (BIO *)0x0) {
    ERR_put_error(0xb,0x76,7,"t_x509.c",0x5a);
    uVar11 = 0;
    goto LAB_08145fc8;
  }
  BIO_ctrl(bp_00,0x6a,0,bp);
  pXVar1 = x->cert_info;
  iVar3 = BIO_write(bp_00,"Certificate:\n",0xd);
  if ((iVar3 < 1) || (iVar3 = BIO_write(bp_00,"    Data:\n",10), iVar3 < 1)) {
LAB_08145fb8:
    uVar11 = 0;
  }
  else {
    lVar4 = ASN1_INTEGER_get(x->cert_info->version);
    iVar3 = BIO_printf(bp_00,"%8sVersion: %lu (0x%lx)\n",&DAT_081ec74a,lVar4 + 1,lVar4);
    if ((iVar3 < 1) || (iVar3 = BIO_write(bp_00,"        Serial Number:",0x16), iVar3 < 1))
    goto LAB_08145fb8;
    a_01 = X509_get_serialNumber(x);
    if (4 < a_01->length) {
      pcVar5 = " (Negative)";
      if (a_01->type != 0x102) {
        pcVar5 = "";
      }
      iVar3 = BIO_printf(bp_00,"\n%12s%s",&DAT_081ec74a,pcVar5);
      if (0 < iVar3) {
        iVar3 = 0;
        do {
          if (a_01->length <= iVar3) goto LAB_08145e58;
          uVar6 = 10;
          if (iVar3 + 1 != a_01->length) {
            uVar6 = 0x3a;
          }
          iVar7 = BIO_printf(bp_00,"%02x%c",(uint)a_01->data[iVar3],uVar6);
          iVar3 = iVar3 + 1;
        } while (0 < iVar7);
      }
      goto LAB_08145fb8;
    }
    lVar4 = ASN1_INTEGER_get(a_01);
    puVar10 = &DAT_081ec74a;
    if (a_01->type == 0x102) {
      lVar4 = -lVar4;
      puVar10 = &DAT_0823b414;
    }
    iVar3 = BIO_printf(bp_00," %s%lu (%s0x%lx)\n",puVar10,lVar4,puVar10,lVar4);
    if (iVar3 < 1) goto LAB_08145fb8;
LAB_08145e58:
    pXVar2 = x->sig_alg;
    iVar3 = BIO_puts(bp_00,"    Signature Algorithm: ");
    if ((iVar3 < 1) || (iVar3 = i2a_ASN1_OBJECT(bp_00,pXVar2->algorithm), iVar3 < 1))
    goto LAB_08145fb8;
    iVar3 = OBJ_obj2nid(pXVar2->algorithm);
    if ((iVar3 != 0) &&
       (((iVar3 = OBJ_find_sigid_algs(iVar3,&local_24,&local_28), iVar3 != 0 &&
         (pEVar9 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_28),
         pEVar9 != (EVP_PKEY_ASN1_METHOD *)0x0)) && (*(code **)(pEVar9 + 0x50) != (code *)0x0)))) {
      iVar3 = (**(code **)(pEVar9 + 0x50))(bp_00,pXVar2,0,9,0);
      if (0 < iVar3) goto LAB_08145eba;
      goto LAB_08145fb8;
    }
    iVar3 = BIO_puts(bp_00,"\n");
    if (iVar3 < 1) goto LAB_08145fb8;
LAB_08145eba:
    iVar3 = BIO_printf(bp_00,"        Issuer:%c",0x20);
    if (iVar3 < 1) goto LAB_08145fb8;
    pXVar8 = X509_get_issuer_name(x);
    iVar3 = X509_NAME_print_ex(bp_00,pXVar8,0x10,0);
    if (((iVar3 < 0) || (iVar3 = BIO_write(bp_00,&DAT_081f11d3,1), iVar3 < 1)) ||
       ((iVar3 = BIO_write(bp_00,"        Validity\n",0x11), iVar3 < 1 ||
        (iVar3 = BIO_write(bp_00,"            Not Before: ",0x18), iVar3 < 1)))) goto LAB_08145fb8;
    a = x->cert_info->validity->notBefore;
    if (a->type == 0x17) {
      iVar3 = ASN1_UTCTIME_print(bp_00,a);
LAB_0814607d:
      if ((iVar3 != 0) && (iVar3 = BIO_write(bp_00,"\n            Not After : ",0x19), 0 < iVar3)) {
        a_00 = x->cert_info->validity->notAfter;
        if (a_00->type == 0x17) {
          iVar3 = ASN1_UTCTIME_print(bp_00,a_00);
        }
        else {
          if (a_00->type != 0x18) goto LAB_08145f5d;
          iVar3 = ASN1_GENERALIZEDTIME_print(bp_00,a_00);
        }
        if (((iVar3 != 0) && (iVar3 = BIO_write(bp_00,&DAT_081f11d3,1), 0 < iVar3)) &&
           (iVar3 = BIO_printf(bp_00,"        Subject:%c",0x20), 0 < iVar3)) {
          pXVar8 = X509_get_subject_name(x);
          iVar3 = X509_NAME_print_ex(bp_00,pXVar8,0x10,0);
          if ((((-1 < iVar3) && (iVar3 = BIO_write(bp_00,&DAT_081f11d3,1), 0 < iVar3)) &&
              ((iVar3 = BIO_write(bp_00,"        Subject Public Key Info:\n",0x21), 0 < iVar3 &&
               ((iVar3 = BIO_printf(bp_00,"%12sPublic Key Algorithm: ",&DAT_081ec74a), 0 < iVar3 &&
                (iVar3 = i2a_ASN1_OBJECT(bp_00,pXVar1->key->algor->algorithm), 0 < iVar3)))))) &&
             (iVar3 = BIO_puts(bp_00,"\n"), 0 < iVar3)) {
            pkey = X509_get_pubkey(x);
            if (pkey == (EVP_PKEY *)0x0) {
              BIO_printf(bp_00,"%12sUnable to load Public Key\n",&DAT_081ec74a);
              ERR_print_errors(bp_00);
            }
            else {
              EVP_PKEY_print_public(bp_00,pkey,0x10,(ASN1_PCTX *)0x0);
              EVP_PKEY_free(pkey);
            }
            X509V3_extensions_print(bp_00,"X509v3 extensions",pXVar1->extensions,0,8);
            iVar3 = X509_signature_print(bp_00,x->sig_alg,x->signature);
            if (0 < iVar3) {
              iVar3 = X509_CERT_AUX_print(bp_00,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
              uVar11 = (uint)(iVar3 != 0);
              goto LAB_08145fba;
            }
          }
        }
      }
      goto LAB_08145fb8;
    }
    if (a->type == 0x18) {
      iVar3 = ASN1_GENERALIZEDTIME_print(bp_00,a);
      goto LAB_0814607d;
    }
LAB_08145f5d:
    uVar11 = 0;
    BIO_write(bp_00,"Bad time value",0xe);
  }
LAB_08145fba:
  BIO_free(bp_00);
LAB_08145fc8:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}

