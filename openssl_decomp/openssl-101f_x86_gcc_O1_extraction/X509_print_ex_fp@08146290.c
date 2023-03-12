
int X509_print_ex_fp(FILE *bp,X509 *x,ulong nmflag,ulong cflag)

{
  X509_CINF *pXVar1;
  X509_ALGOR *pXVar2;
  ASN1_UTCTIME *a;
  ASN1_GENERALIZEDTIME *a_00;
  BIO_METHOD *type;
  BIO *bp_00;
  ASN1_INTEGER *a_01;
  char *pcVar3;
  int iVar4;
  EVP_PKEY *pkey;
  X509_NAME *pXVar5;
  int iVar6;
  EVP_PKEY_ASN1_METHOD *pEVar7;
  long lVar8;
  undefined1 *puVar9;
  uint uVar10;
  int in_GS_OFFSET;
  char local_3d;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 == (BIO *)0x0) {
    ERR_put_error(0xb,0x76,7,"t_x509.c",0x5a);
    uVar10 = 0;
    goto LAB_081463d8;
  }
  BIO_ctrl(bp_00,0x6a,0,bp);
  if ((nmflag & 0xf0000) == 0x40000) {
    uVar10 = 0xc;
    local_3d = '\n';
  }
  else {
    local_3d = ' ';
    uVar10 = -(uint)(nmflag == 0) & 0x10;
  }
  pXVar1 = x->cert_info;
  if (((cflag & 1) == 0) &&
     ((iVar6 = BIO_write(bp_00,"Certificate:\n",0xd), iVar6 < 1 ||
      (iVar6 = BIO_write(bp_00,"    Data:\n",10), iVar6 < 1)))) {
LAB_081463c8:
    uVar10 = 0;
  }
  else {
    pcVar3 = (char *)bp;
    if ((cflag & 2) == 0) {
      lVar8 = ASN1_INTEGER_get(x->cert_info->version);
      iVar6 = BIO_printf(bp_00,"%8sVersion: %lu (0x%lx)\n",&DAT_081ec74a,lVar8 + 1,lVar8);
      pcVar3 = (char *)bp;
      if (iVar6 < 1) goto LAB_081463c8;
    }
    if ((cflag & 4) == 0) {
      iVar6 = BIO_write(bp_00,"        Serial Number:",0x16);
      if (0 < iVar6) {
        a_01 = X509_get_serialNumber(x);
        if (a_01->length < 5) {
          lVar8 = ASN1_INTEGER_get(a_01);
          puVar9 = &DAT_081ec74a;
          if (a_01->type == 0x102) {
            lVar8 = -lVar8;
            puVar9 = &DAT_0823b414;
          }
          iVar6 = BIO_printf(bp_00," %s%lu (%s0x%lx)\n",puVar9,lVar8,puVar9,lVar8);
          if (0 < iVar6) goto LAB_08146325;
        }
        else {
          pcVar3 = " (Negative)";
          if (a_01->type != 0x102) {
            pcVar3 = &DAT_081ec74a;
          }
          iVar6 = BIO_printf(bp_00,"\n%12s%s",&DAT_081ec74a,pcVar3);
          if (0 < iVar6) {
            iVar6 = 0;
            do {
              if (a_01->length <= iVar6) goto LAB_08146325;
              pcVar3 = (char *)0xa;
              if (iVar6 + 1 != a_01->length) {
                pcVar3 = (char *)0x3a;
              }
              iVar4 = BIO_printf(bp_00,"%02x%c",(uint)a_01->data[iVar6],pcVar3);
              iVar6 = iVar6 + 1;
            } while (0 < iVar4);
          }
        }
      }
      goto LAB_081463c8;
    }
LAB_08146325:
    if ((cflag & 8) != 0) goto LAB_08146331;
    pXVar2 = x->sig_alg;
    iVar6 = BIO_puts(bp_00,"    Signature Algorithm: ");
    if ((iVar6 < 1) || (iVar6 = i2a_ASN1_OBJECT(bp_00,pXVar2->algorithm), iVar6 < 1))
    goto LAB_081463c8;
    iVar6 = OBJ_obj2nid(pXVar2->algorithm);
    if ((iVar6 != 0) &&
       (((iVar6 = OBJ_find_sigid_algs(iVar6,&local_24,&local_28), iVar6 != 0 &&
         (pEVar7 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_28),
         pEVar7 != (EVP_PKEY_ASN1_METHOD *)0x0)) && (*(code **)(pEVar7 + 0x50) != (code *)0x0)))) {
      iVar6 = (**(code **)(pEVar7 + 0x50))(bp_00,pXVar2,0,9,0);
      if (0 < iVar6) goto LAB_08146331;
      goto LAB_081463c8;
    }
    iVar6 = BIO_puts(bp_00,"\n");
    if (iVar6 < 1) goto LAB_081463c8;
LAB_08146331:
    if ((cflag & 0x10) == 0) {
      iVar6 = BIO_printf(bp_00,"        Issuer:%c",(int)local_3d,pcVar3);
      if (0 < iVar6) {
        pXVar5 = X509_get_issuer_name(x);
        iVar6 = X509_NAME_print_ex(bp_00,pXVar5,uVar10,nmflag);
        if ((-1 < iVar6) && (iVar6 = BIO_write(bp_00,&DAT_081f11d3,1), 0 < iVar6))
        goto LAB_0814633d;
      }
      goto LAB_081463c8;
    }
LAB_0814633d:
    if ((cflag & 0x20) != 0) {
LAB_08146349:
      if ((cflag & 0x40) == 0) {
        iVar6 = BIO_printf(bp_00,"        Subject:%c",(int)local_3d);
        if (0 < iVar6) {
          pXVar5 = X509_get_subject_name(x);
          iVar6 = X509_NAME_print_ex(bp_00,pXVar5,uVar10,nmflag);
          if ((-1 < iVar6) && (iVar6 = BIO_write(bp_00,&DAT_081f11d3,1), 0 < iVar6))
          goto LAB_08146355;
        }
      }
      else {
LAB_08146355:
        if ((cflag & 0x80) == 0) {
          iVar6 = BIO_write(bp_00,"        Subject Public Key Info:\n",0x21);
          if ((((iVar6 < 1) ||
               (iVar6 = BIO_printf(bp_00,"%12sPublic Key Algorithm: ",&DAT_081ec74a), iVar6 < 1)) ||
              (iVar6 = i2a_ASN1_OBJECT(bp_00,pXVar1->key->algor->algorithm), iVar6 < 1)) ||
             (iVar6 = BIO_puts(bp_00,"\n"), iVar6 < 1)) goto LAB_081463c8;
          pkey = X509_get_pubkey(x);
          if (pkey == (EVP_PKEY *)0x0) {
            BIO_printf(bp_00,"%12sUnable to load Public Key\n",&DAT_081ec74a);
            ERR_print_errors(bp_00);
          }
          else {
            EVP_PKEY_print_public(bp_00,pkey,0x10,(ASN1_PCTX *)0x0);
            EVP_PKEY_free(pkey);
          }
        }
        if ((cflag & 0x100) == 0) {
          X509V3_extensions_print(bp_00,"X509v3 extensions",pXVar1->extensions,cflag,8);
        }
        if (((cflag & 0x200) != 0) ||
           (iVar6 = X509_signature_print(bp_00,x->sig_alg,x->signature), 0 < iVar6)) {
          if ((cflag & 0x400) == 0) {
            iVar6 = X509_CERT_AUX_print(bp_00,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
            uVar10 = (uint)(iVar6 != 0);
          }
          else {
            uVar10 = 1;
          }
          goto LAB_081463ca;
        }
      }
      goto LAB_081463c8;
    }
    iVar6 = BIO_write(bp_00,"        Validity\n",0x11);
    if ((iVar6 < 1) || (iVar6 = BIO_write(bp_00,"            Not Before: ",0x18), iVar6 < 1))
    goto LAB_081463c8;
    a = x->cert_info->validity->notBefore;
    if (a->type == 0x17) {
      iVar6 = ASN1_UTCTIME_print(bp_00,a);
LAB_08146855:
      if ((iVar6 == 0) || (iVar6 = BIO_write(bp_00,"\n            Not After : ",0x19), iVar6 < 1))
      goto LAB_081463c8;
      a_00 = x->cert_info->validity->notAfter;
      if (a_00->type == 0x17) {
        iVar6 = ASN1_UTCTIME_print(bp_00,a_00);
      }
      else {
        if (a_00->type != 0x18) goto LAB_081466da;
        iVar6 = ASN1_GENERALIZEDTIME_print(bp_00,a_00);
      }
      if ((iVar6 == 0) || (iVar6 = BIO_write(bp_00,&DAT_081f11d3,1), iVar6 < 1)) goto LAB_081463c8;
      goto LAB_08146349;
    }
    if (a->type == 0x18) {
      iVar6 = ASN1_GENERALIZEDTIME_print(bp_00,a);
      goto LAB_08146855;
    }
LAB_081466da:
    uVar10 = 0;
    BIO_write(bp_00,"Bad time value",0xe);
  }
LAB_081463ca:
  BIO_free(bp_00);
LAB_081463d8:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

