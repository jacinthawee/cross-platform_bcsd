
EVP_PKEY * d2i_AutoPrivateKey(EVP_PKEY **a,uchar **pp,long length)

{
  byte bVar1;
  undefined *puVar2;
  ASN1_SEQUENCE_ANY *pAVar3;
  int iVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  PKCS8_PRIV_KEY_INFO *pPVar6;
  undefined4 uVar7;
  BIO *out;
  int *piVar8;
  int iVar9;
  ASN1_OBJECT **ppAVar10;
  undefined4 uVar11;
  int iVar12;
  ASN1_OBJECT *a_00;
  int iVar13;
  char **ppcVar14;
  byte *pbVar15;
  uchar **ppuVar16;
  byte *pbVar17;
  char *pcVar18;
  EVP_PKEY *pEVar19;
  uchar *puVar20;
  int iStack_90;
  char **ppcStack_84;
  char *pcStack_80;
  int iStack_7c;
  uchar *local_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_28 = *pp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar3 = d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_28,length);
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(pAVar3);
  if (iVar4 == 6) {
    iVar4 = 0x74;
LAB_00558ad8:
    (*(code *)PTR_sk_pop_free_006a8158)(pAVar3,PTR_ASN1_TYPE_free_006a8598);
    if ((a == (EVP_PKEY **)0x0) || (pEVar19 = *a, pEVar19 == (EVP_PKEY *)0x0)) {
      pEVar19 = EVP_PKEY_new();
      if (pEVar19 != (EVP_PKEY *)0x0) goto LAB_00558b18;
      ppuVar16 = (uchar **)0x9a;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x9a,6,"d2i_pr.c",0x50);
      pEVar19 = (EVP_PKEY *)0x0;
    }
    else {
      if (pEVar19->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
        pEVar19->engine = (ENGINE *)0x0;
      }
LAB_00558b18:
      iVar4 = EVP_PKEY_set_type(pEVar19,iVar4);
      if (iVar4 == 0) {
        uVar11 = 0xa3;
        uVar7 = 0x62;
LAB_00558c10:
        pp = (uchar **)0x9a;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x9a,uVar11,"d2i_pr.c",uVar7);
      }
      else {
        pEVar5 = pEVar19->ameth;
        if (*(code **)(pEVar5 + 0x5c) != (code *)0x0) {
          ppuVar16 = pp;
          iVar4 = (**(code **)(pEVar5 + 0x5c))(pEVar19,pp,length);
          if (iVar4 == 0) {
            pEVar5 = pEVar19->ameth;
            goto LAB_00558b58;
          }
LAB_00558bb4:
          if (a != (EVP_PKEY **)0x0) goto LAB_00558bbc;
          goto LAB_00558bc4;
        }
LAB_00558b58:
        if (*(int *)(pEVar5 + 0x24) == 0) {
          uVar11 = 0xd;
          uVar7 = 0x75;
          goto LAB_00558c10;
        }
        pPVar6 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
        if (pPVar6 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          EVP_PKEY_free(pEVar19);
          pEVar19 = EVP_PKCS82PKEY(pPVar6);
          PKCS8_PRIV_KEY_INFO_free(pPVar6);
          ppuVar16 = pp;
          goto LAB_00558bb4;
        }
      }
      if ((a == (EVP_PKEY **)0x0) || (pEVar19 != *a)) {
        EVP_PKEY_free(pEVar19);
        pEVar19 = (EVP_PKEY *)0x0;
        ppuVar16 = pp;
      }
      else {
        pEVar19 = (EVP_PKEY *)0x0;
        ppuVar16 = pp;
      }
    }
  }
  else {
    iVar4 = (*(code *)PTR_sk_num_006a7f2c)(pAVar3);
    if (iVar4 == 4) {
      iVar4 = 0x198;
      goto LAB_00558ad8;
    }
    iVar4 = (*(code *)PTR_sk_num_006a7f2c)(pAVar3);
    if (iVar4 != 3) {
      iVar4 = 6;
      goto LAB_00558ad8;
    }
    pPVar6 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,pp,length);
    ppuVar16 = (uchar **)PTR_ASN1_TYPE_free_006a8598;
    (*(code *)PTR_sk_pop_free_006a8158)(pAVar3);
    if (pPVar6 == (PKCS8_PRIV_KEY_INFO *)0x0) {
      ppuVar16 = (uchar **)0xcf;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xcf,0xa7,"d2i_pr.c",0x9d);
      pEVar19 = (EVP_PKEY *)0x0;
      goto LAB_00558bc4;
    }
    pEVar19 = EVP_PKCS82PKEY(pPVar6);
    PKCS8_PRIV_KEY_INFO_free(pPVar6);
    if (a == (EVP_PKEY **)0x0) goto LAB_00558bc4;
LAB_00558bbc:
    *a = pEVar19;
  }
LAB_00558bc4:
  if (local_24 == *(int *)puVar2) {
    return pEVar19;
  }
  iVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar7 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  out = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar7);
  if (out == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7a,7,"t_req.c",0x51);
    return (EVP_PKEY *)0x0;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(out,0x6a,0,iVar4);
  puVar20 = *ppuVar16;
  iVar4 = (*(code *)PTR_BIO_write_006a7f14)(out,"Certificate Request:\n",0x15);
  if ((0 < iVar4) && (iVar4 = (*(code *)PTR_BIO_write_006a7f14)(out,"    Data:\n",10), 0 < iVar4)) {
    piVar8 = *(int **)(puVar20 + 0xc);
    if (piVar8[1] == 0x102) {
      pcVar18 = "-";
    }
    else {
      pcVar18 = "";
    }
    if (*piVar8 < 1) {
      iVar4 = 0;
    }
    else {
      pbVar15 = (byte *)piVar8[2];
      iVar4 = 0;
      pbVar17 = pbVar15 + *piVar8;
      do {
        bVar1 = *pbVar15;
        pbVar15 = pbVar15 + 1;
        iVar4 = (uint)bVar1 + iVar4 * 0x100;
      } while (pbVar17 != pbVar15);
    }
    iVar4 = (*(code *)PTR_BIO_printf_006a7f38)
                      (out,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar18,iVar4,pcVar18,iVar4);
    if (((((0 < iVar4) &&
          (iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(out,"        Subject:%c",0x20), 0 < iVar4)) &&
         (iVar4 = X509_NAME_print_ex(out,*(X509_NAME **)(puVar20 + 0x10),0x10,0), -1 < iVar4)) &&
        ((iVar4 = (*(code *)PTR_BIO_write_006a7f14)(out,"\n",1), 0 < iVar4 &&
         (iVar4 = (*(code *)PTR_BIO_write_006a7f14)(out,"        Subject Public Key Info:\n",0x21),
         0 < iVar4)))) &&
       ((iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(out,"%12sPublic Key Algorithm: ",""), 0 < iVar4
        && ((iVar4 = i2a_ASN1_OBJECT(out,*(ASN1_OBJECT **)**(undefined4 **)(puVar20 + 0x14)),
            0 < iVar4 && (iVar4 = (*(code *)PTR_BIO_puts_006a8058)(out,"\n"), 0 < iVar4)))))) {
      pEVar19 = (EVP_PKEY *)(*(code *)PTR_X509_REQ_get_pubkey_006a7ff4)(ppuVar16);
      if (pEVar19 == (EVP_PKEY *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)(out,"%12sUnable to load Public Key\n","");
        (*(code *)PTR_ERR_print_errors_006a7f40)(out);
      }
      else {
        EVP_PKEY_print_public(out,pEVar19,0x10,(ASN1_PCTX *)0x0);
        EVP_PKEY_free(pEVar19);
      }
      iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(out,"%8sAttributes:\n","");
      if (0 < iVar4) {
        uVar7 = *(undefined4 *)(*ppuVar16 + 0x18);
        iVar4 = (*(code *)PTR_sk_num_006a7f2c)(uVar7);
        if (iVar4 == 0) {
          iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(out,"%12sa0:00\n","");
          if (iVar4 < 1) goto LAB_005590a0;
        }
        else {
          for (iVar4 = 0; iVar9 = (*(code *)PTR_sk_num_006a7f2c)(uVar7), iVar4 < iVar9;
              iVar4 = iVar4 + 1) {
            ppAVar10 = (ASN1_OBJECT **)(*(code *)PTR_sk_value_006a7f24)(uVar7,iVar4);
            uVar11 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*ppAVar10);
            iVar9 = (*(code *)PTR_X509_REQ_extension_nid_006a9e68)(uVar11);
            if (iVar9 == 0) {
              iVar9 = (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066a4d0,"");
              if (iVar9 < 1) goto LAB_005590a0;
              iVar9 = i2a_ASN1_OBJECT(out,*ppAVar10);
              if (iVar9 < 1) {
                iStack_90 = 0;
                pcStack_80 = (char *)0x0;
                ppcStack_84 = (char **)0x0;
                iStack_7c = 1;
              }
              else {
                if (ppAVar10[1] == (ASN1_OBJECT *)0x0) {
                  iStack_7c = (*(code *)PTR_sk_num_006a7f2c)(ppAVar10[2]);
                  iStack_90 = 0;
                  goto LAB_00559440;
                }
                iStack_90 = 0;
                iStack_7c = 1;
                pcStack_80 = ppAVar10[2]->sn;
                ppcStack_84 = ppAVar10[2]->ln;
              }
              while( true ) {
                iVar9 = 0x19 - iVar9;
                if (0 < iVar9) {
                  do {
                    iVar13 = (*(code *)PTR_BIO_write_006a7f14)(out,&DAT_0063f0b8,1);
                    iVar9 = iVar9 + -1;
                    if (iVar13 != 1) goto LAB_005590a0;
                  } while (iVar9 != 0);
                }
                iVar13 = (*(code *)PTR_BIO_puts_006a8058)(out,":");
                if (iVar13 < 1) goto LAB_005590a0;
                if ((pcStack_80 + -0x13 < (char *)0x2) || (pcStack_80 == (char *)0x16)) {
                  pcVar18 = (char *)(*(code *)PTR_BIO_write_006a7f14)
                                              (out,ppcStack_84[2],*ppcStack_84);
                  if (pcVar18 != *ppcStack_84) goto LAB_005590a0;
                  (*(code *)PTR_BIO_puts_006a8058)(out,"\n");
                }
                else {
                  (*(code *)PTR_BIO_puts_006a8058)(out,"unable to print attribute\n");
                }
                iStack_90 = iStack_90 + 1;
                if (iStack_7c <= iStack_90) break;
LAB_00559440:
                ppcVar14 = (char **)(*(code *)PTR_sk_value_006a7f24)(ppAVar10[2],iStack_90);
                pcStack_80 = *ppcVar14;
                ppcStack_84 = (char **)ppcVar14[1];
              }
            }
          }
        }
        iVar4 = (*(code *)PTR_X509_REQ_get_extensions_006a8c9c)(ppuVar16);
        if (iVar4 == 0) {
LAB_005593b0:
          iVar4 = X509_signature_print(out,(X509_ALGOR *)ppuVar16[1],(ASN1_STRING *)ppuVar16[2]);
          if (iVar4 != 0) {
            pEVar19 = (EVP_PKEY *)0x1;
            goto LAB_005590c8;
          }
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)(out,"%8sRequested Extensions:\n","");
          iVar9 = 0;
          do {
            iVar13 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
            if (iVar13 <= iVar9) {
              (*(code *)PTR_sk_pop_free_006a8158)(iVar4,PTR_X509_EXTENSION_free_006a8268);
              goto LAB_005593b0;
            }
            iVar13 = (*(code *)PTR_sk_value_006a7f24)(iVar4,iVar9);
            iVar12 = (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066a4d0,"");
            if (iVar12 < 1) break;
            a_00 = (ASN1_OBJECT *)(*(code *)PTR_X509_EXTENSION_get_object_006a8ca0)(iVar13);
            i2a_ASN1_OBJECT(out,a_00);
            iVar12 = (*(code *)PTR_X509_EXTENSION_get_critical_006a9e6c)(iVar13);
            pcVar18 = "";
            if (iVar12 != 0) {
              pcVar18 = "critical";
            }
            iVar12 = (*(code *)PTR_BIO_printf_006a7f38)(out,": %s\n",pcVar18);
            if (iVar12 < 1) break;
            iVar12 = (*(code *)PTR_X509V3_EXT_print_006a9e70)(out,iVar13,0,0x10);
            iVar9 = iVar9 + 1;
            if (iVar12 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)(out,&DAT_0066a510,"");
              ASN1_STRING_print(out,*(ASN1_STRING **)(iVar13 + 8));
            }
            iVar13 = (*(code *)PTR_BIO_write_006a7f14)(out,"\n",1);
          } while (0 < iVar13);
        }
      }
    }
  }
LAB_005590a0:
  pEVar19 = (EVP_PKEY *)0x0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x79,7,"t_req.c",0x103);
LAB_005590c8:
  (*(code *)PTR_BIO_free_006a7f70)(out);
  return pEVar19;
}

