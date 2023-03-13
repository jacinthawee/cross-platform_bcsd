
int X509_print_ex(BIO *bp,X509 *x,ulong nmflag,ulong cflag)

{
  X509_CINF *pXVar1;
  X509_ALGOR *pXVar2;
  ASN1_GENERALIZEDTIME *pAVar3;
  ASN1_INTEGER *a;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  X509_NAME *pXVar8;
  EVP_PKEY *pkey;
  long lVar9;
  EVP_PKEY_ASN1_METHOD *pEVar10;
  undefined1 *puVar11;
  uint uVar12;
  int in_GS_OFFSET;
  char local_35;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((nmflag & 0xf0000) == 0x40000) {
    uVar12 = 0xc;
    local_35 = '\n';
  }
  else {
    local_35 = ' ';
    uVar12 = -(uint)(nmflag == 0) & 0x10;
  }
  pXVar1 = x->cert_info;
  if (((cflag & 1) != 0) ||
     ((iVar7 = BIO_write(bp,"Certificate:\n",0xd), 0 < iVar7 &&
      (iVar7 = BIO_write(bp,"    Data:\n",10), 0 < iVar7)))) {
    if ((cflag & 2) == 0) {
      lVar9 = ASN1_INTEGER_get(x->cert_info->version);
      iVar7 = BIO_printf(bp,"%8sVersion: %lu (0x%lx)\n",&DAT_081eca46,lVar9 + 1,lVar9);
      if (iVar7 < 1) goto LAB_08142cc8;
    }
    if ((cflag & 4) == 0) {
      iVar7 = BIO_write(bp,"        Serial Number:",0x16);
      if (0 < iVar7) {
        a = X509_get_serialNumber(x);
        if ((a->length < 4) || ((a->length == 4 && (-1 < (char)*a->data)))) {
          lVar9 = ASN1_INTEGER_get(a);
          puVar11 = &DAT_081eca46;
          if (a->type == 0x102) {
            lVar9 = -lVar9;
            puVar11 = &DAT_0823b914;
          }
          iVar7 = BIO_printf(bp," %s%lu (%s0x%lx)\n",puVar11,lVar9,puVar11,lVar9);
          if (iVar7 < 1) {
            uVar12 = 0;
            goto LAB_08142c70;
          }
          goto LAB_08142c23;
        }
        pcVar4 = " (Negative)";
        if (a->type != 0x102) {
          pcVar4 = "";
        }
        iVar7 = BIO_printf(bp,"\n%12s%s",&DAT_081eca46,pcVar4);
        if (0 < iVar7) {
          iVar7 = 0;
          do {
            if (a->length <= iVar7) goto LAB_08142c23;
            uVar5 = 10;
            if (a->length != iVar7 + 1) {
              uVar5 = 0x3a;
            }
            iVar6 = BIO_printf(bp,"%02x%c",(uint)a->data[iVar7],uVar5);
            iVar7 = iVar7 + 1;
          } while (0 < iVar6);
        }
      }
    }
    else {
LAB_08142c23:
      if ((cflag & 8) == 0) {
        pXVar2 = pXVar1->signature;
        iVar7 = BIO_puts(bp,"    Signature Algorithm: ");
        if ((0 < iVar7) && (iVar7 = i2a_ASN1_OBJECT(bp,pXVar2->algorithm), 0 < iVar7)) {
          iVar7 = OBJ_obj2nid(pXVar2->algorithm);
          if ((iVar7 == 0) ||
             (((iVar7 = OBJ_find_sigid_algs(iVar7,&local_24,&local_28), iVar7 == 0 ||
               (pEVar10 = EVP_PKEY_asn1_find((ENGINE **)0x0,local_28),
               pEVar10 == (EVP_PKEY_ASN1_METHOD *)0x0)) ||
              (*(code **)(pEVar10 + 0x50) == (code *)0x0)))) {
            iVar7 = BIO_puts(bp,"\n");
          }
          else {
            iVar7 = (**(code **)(pEVar10 + 0x50))(bp,pXVar2,0,9,0);
          }
          if (0 < iVar7) goto LAB_08142c2c;
        }
      }
      else {
LAB_08142c2c:
        if ((cflag & 0x10) == 0) {
          iVar7 = BIO_printf(bp,"        Issuer:%c",(int)local_35);
          if (0 < iVar7) {
            pXVar8 = X509_get_issuer_name(x);
            iVar7 = X509_NAME_print_ex(bp,pXVar8,uVar12,nmflag);
            if ((-1 < iVar7) && (iVar7 = BIO_write(bp,&DAT_081f15cb,1), 0 < iVar7))
            goto LAB_08142c35;
          }
        }
        else {
LAB_08142c35:
          if ((cflag & 0x20) == 0) {
            iVar7 = BIO_write(bp,"        Validity\n",0x11);
            if ((iVar7 < 1) || (iVar7 = BIO_write(bp,"            Not Before: ",0x18), iVar7 < 1))
            goto LAB_08142cc8;
            pAVar3 = x->cert_info->validity->notBefore;
            if (pAVar3->type != 0x17) {
              if (pAVar3->type == 0x18) {
                iVar7 = ASN1_GENERALIZEDTIME_print(bp,pAVar3);
                goto LAB_08143115;
              }
LAB_08142f13:
              BIO_write(bp,"Bad time value",0xe);
              uVar12 = 0;
              goto LAB_08142c70;
            }
            iVar7 = ASN1_UTCTIME_print(bp,pAVar3);
LAB_08143115:
            if ((iVar7 == 0) || (iVar7 = BIO_write(bp,"\n            Not After : ",0x19), iVar7 < 1)
               ) goto LAB_08142cc8;
            pAVar3 = x->cert_info->validity->notAfter;
            if (pAVar3->type == 0x17) {
              iVar7 = ASN1_UTCTIME_print(bp,pAVar3);
            }
            else {
              if (pAVar3->type != 0x18) goto LAB_08142f13;
              iVar7 = ASN1_GENERALIZEDTIME_print(bp,pAVar3);
            }
            if (iVar7 == 0) goto LAB_08142cc8;
            iVar7 = BIO_write(bp,&DAT_081f15cb,1);
            if (iVar7 < 1) {
              uVar12 = 0;
              goto LAB_08142c70;
            }
          }
          if ((cflag & 0x40) == 0) {
            iVar7 = BIO_printf(bp,"        Subject:%c",(int)local_35);
            if (0 < iVar7) {
              pXVar8 = X509_get_subject_name(x);
              iVar7 = X509_NAME_print_ex(bp,pXVar8,uVar12,nmflag);
              if (-1 < iVar7) {
                iVar7 = BIO_write(bp,&DAT_081f15cb,1);
                if (iVar7 < 1) {
                  uVar12 = 0;
                  goto LAB_08142c70;
                }
                goto LAB_08142c47;
              }
            }
          }
          else {
LAB_08142c47:
            if ((cflag & 0x80) == 0) {
              iVar7 = BIO_write(bp,"        Subject Public Key Info:\n",0x21);
              if ((((iVar7 < 1) ||
                   (iVar7 = BIO_printf(bp,"%12sPublic Key Algorithm: ",&DAT_081eca46), iVar7 < 1))
                  || (iVar7 = i2a_ASN1_OBJECT(bp,pXVar1->key->algor->algorithm), iVar7 < 1)) ||
                 (iVar7 = BIO_puts(bp,"\n"), iVar7 < 1)) goto LAB_08142cc8;
              pkey = X509_get_pubkey(x);
              if (pkey == (EVP_PKEY *)0x0) {
                BIO_printf(bp,"%12sUnable to load Public Key\n",&DAT_081eca46);
                ERR_print_errors(bp);
              }
              else {
                EVP_PKEY_print_public(bp,pkey,0x10,(ASN1_PCTX *)0x0);
                EVP_PKEY_free(pkey);
              }
            }
            if ((cflag & 0x100) == 0) {
              X509V3_extensions_print(bp,"X509v3 extensions",pXVar1->extensions,cflag,8);
            }
            if (((cflag & 0x200) != 0) ||
               (iVar7 = X509_signature_print(bp,x->sig_alg,x->signature), 0 < iVar7)) {
              uVar12 = 1;
              if ((cflag & 0x400) == 0) {
                iVar7 = X509_CERT_AUX_print(bp,*(X509_CERT_AUX **)(x->sha1_hash + 0xc),0);
                uVar12 = (uint)(iVar7 != 0);
              }
              goto LAB_08142c70;
            }
          }
        }
      }
    }
  }
LAB_08142cc8:
  uVar12 = 0;
LAB_08142c70:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}

