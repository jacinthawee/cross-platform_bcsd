
EVP_PKEY * d2i_AutoPrivateKey(EVP_PKEY **a,uchar **pp,long length)

{
  byte bVar1;
  undefined *puVar2;
  ASN1_SEQUENCE_ANY *pAVar3;
  int iVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  PKCS8_PRIV_KEY_INFO *pPVar6;
  EVP_PKEY *pEVar7;
  undefined4 uVar8;
  BIO *out;
  int *piVar9;
  int iVar10;
  ASN1_OBJECT **ppAVar11;
  undefined4 uVar12;
  int iVar13;
  ASN1_OBJECT *a_00;
  int iVar14;
  char **ppcVar15;
  byte *pbVar16;
  uchar **in;
  byte *pbVar17;
  char *pcVar18;
  EVP_PKEY *pEVar19;
  uchar *puVar20;
  int iStack_98;
  char **ppcStack_8c;
  char *pcStack_88;
  int iStack_84;
  uchar *local_2c;
  uchar *local_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *pp;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAVar3 = d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_2c,length);
  local_2c = *pp;
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pAVar3);
  if (iVar4 == 6) {
    iVar4 = 0x74;
LAB_00555a58:
    (*(code *)PTR_sk_pop_free_006a7058)(pAVar3,PTR_ASN1_TYPE_free_006a7498);
    local_28 = *pp;
    if ((a == (EVP_PKEY **)0x0) || (pEVar19 = *a, pEVar19 == (EVP_PKEY *)0x0)) {
      pEVar19 = EVP_PKEY_new();
      if (pEVar19 != (EVP_PKEY *)0x0) goto LAB_00555aa0;
      in = (uchar **)0x9a;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x9a,6,"d2i_pr.c",0x4f);
      pEVar7 = (EVP_PKEY *)0x0;
    }
    else {
      if (pEVar19->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        pEVar19->engine = (ENGINE *)0x0;
      }
LAB_00555aa0:
      iVar4 = EVP_PKEY_set_type(pEVar19,iVar4);
      if (iVar4 == 0) {
        uVar12 = 0xa3;
        uVar8 = 0x5d;
LAB_00555b78:
        in = (uchar **)0x9a;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x9a,uVar12,"d2i_pr.c",uVar8);
      }
      else {
        pEVar5 = pEVar19->ameth;
        in = &local_28;
        if (*(code **)(pEVar5 + 0x5c) != (code *)0x0) {
          iVar4 = (**(code **)(pEVar5 + 0x5c))(pEVar19,in,length);
          pEVar7 = pEVar19;
          if (iVar4 == 0) {
            pEVar5 = pEVar19->ameth;
            goto LAB_00555ae0;
          }
LAB_00555b44:
          *pp = local_28;
          if (a != (EVP_PKEY **)0x0) goto LAB_00555b50;
          goto LAB_00555bb0;
        }
LAB_00555ae0:
        in = &local_28;
        if (*(int *)(pEVar5 + 0x24) == 0) {
          uVar12 = 0xd;
          uVar8 = 0x70;
          goto LAB_00555b78;
        }
        pPVar6 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,in,length);
        if (pPVar6 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          pEVar7 = EVP_PKCS82PKEY(pPVar6);
          PKCS8_PRIV_KEY_INFO_free(pPVar6);
          if (pEVar7 != (EVP_PKEY *)0x0) {
            EVP_PKEY_free(pEVar19);
            goto LAB_00555b44;
          }
        }
      }
      if ((a == (EVP_PKEY **)0x0) || (pEVar7 = (EVP_PKEY *)0x0, pEVar19 != *a)) {
        EVP_PKEY_free(pEVar19);
        pEVar7 = (EVP_PKEY *)0x0;
      }
    }
  }
  else {
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pAVar3);
    if (iVar4 == 4) {
      iVar4 = 0x198;
      goto LAB_00555a58;
    }
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pAVar3);
    if (iVar4 != 3) {
      iVar4 = 6;
      goto LAB_00555a58;
    }
    pPVar6 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&local_2c,length);
    in = (uchar **)PTR_ASN1_TYPE_free_006a7498;
    (*(code *)PTR_sk_pop_free_006a7058)(pAVar3);
    if (pPVar6 == (PKCS8_PRIV_KEY_INFO *)0x0) {
      in = (uchar **)0xcf;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xcf,0xa7,"d2i_pr.c",0xa1);
      pEVar7 = (EVP_PKEY *)0x0;
      goto LAB_00555bb0;
    }
    pEVar7 = EVP_PKCS82PKEY(pPVar6);
    PKCS8_PRIV_KEY_INFO_free(pPVar6);
    if (pEVar7 == (EVP_PKEY *)0x0) {
      pEVar7 = (EVP_PKEY *)0x0;
      goto LAB_00555bb0;
    }
    *pp = local_2c;
    if (a == (EVP_PKEY **)0x0) goto LAB_00555bb0;
LAB_00555b50:
    *a = pEVar7;
  }
LAB_00555bb0:
  if (local_24 == *(int *)puVar2) {
    return pEVar7;
  }
  iVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar8 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  out = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar8);
  if (out == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7a,7,"t_req.c",0x50);
    return (EVP_PKEY *)0x0;
  }
  (*(code *)PTR_BIO_ctrl_006a6e18)(out,0x6a,0,iVar4);
  puVar20 = *in;
  iVar4 = (*(code *)PTR_BIO_write_006a6e14)(out,"Certificate Request:\n",0x15);
  if ((0 < iVar4) && (iVar4 = (*(code *)PTR_BIO_write_006a6e14)(out,"    Data:\n",10), 0 < iVar4)) {
    piVar9 = *(int **)(puVar20 + 0xc);
    if (piVar9[1] == 0x102) {
      pcVar18 = "-";
    }
    else {
      pcVar18 = "";
    }
    if (*piVar9 < 1) {
      iVar4 = 0;
    }
    else {
      pbVar16 = (byte *)piVar9[2];
      iVar4 = 0;
      pbVar17 = pbVar16 + *piVar9;
      do {
        bVar1 = *pbVar16;
        pbVar16 = pbVar16 + 1;
        iVar4 = (uint)bVar1 + iVar4 * 0x100;
      } while (pbVar17 != pbVar16);
    }
    iVar4 = (*(code *)PTR_BIO_printf_006a6e38)
                      (out,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar18,iVar4,pcVar18,iVar4);
    if (((((0 < iVar4) &&
          (iVar4 = (*(code *)PTR_BIO_printf_006a6e38)(out,"        Subject:%c",0x20), 0 < iVar4)) &&
         (iVar4 = X509_NAME_print_ex(out,*(X509_NAME **)(puVar20 + 0x10),0x10,0), -1 < iVar4)) &&
        ((iVar4 = (*(code *)PTR_BIO_write_006a6e14)(out,"\n",1), 0 < iVar4 &&
         (iVar4 = (*(code *)PTR_BIO_write_006a6e14)(out,"        Subject Public Key Info:\n",0x21),
         0 < iVar4)))) &&
       ((iVar4 = (*(code *)PTR_BIO_printf_006a6e38)(out,"%12sPublic Key Algorithm: ",""), 0 < iVar4
        && ((iVar4 = i2a_ASN1_OBJECT(out,*(ASN1_OBJECT **)**(undefined4 **)(puVar20 + 0x14)),
            0 < iVar4 && (iVar4 = (*(code *)PTR_BIO_puts_006a6f58)(out,"\n"), 0 < iVar4)))))) {
      pEVar19 = (EVP_PKEY *)(*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(in);
      if (pEVar19 == (EVP_PKEY *)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)(out,"%12sUnable to load Public Key\n","");
        (*(code *)PTR_ERR_print_errors_006a6e40)(out);
      }
      else {
        EVP_PKEY_print_public(out,pEVar19,0x10,(ASN1_PCTX *)0x0);
        EVP_PKEY_free(pEVar19);
      }
      iVar4 = (*(code *)PTR_BIO_printf_006a6e38)(out,"%8sAttributes:\n","");
      if (0 < iVar4) {
        uVar8 = *(undefined4 *)(*in + 0x18);
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(uVar8);
        if (iVar4 == 0) {
          iVar4 = (*(code *)PTR_BIO_printf_006a6e38)(out,"%12sa0:00\n","");
          if (iVar4 < 1) goto LAB_00556040;
        }
        else {
          for (iVar4 = 0; iVar10 = (*(code *)PTR_sk_num_006a6e2c)(uVar8), iVar4 < iVar10;
              iVar4 = iVar4 + 1) {
            ppAVar11 = (ASN1_OBJECT **)(*(code *)PTR_sk_value_006a6e24)(uVar8,iVar4);
            uVar12 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*ppAVar11);
            iVar10 = (*(code *)PTR_X509_REQ_extension_nid_006a8d48)(uVar12);
            if (iVar10 == 0) {
              iVar10 = (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_00669a00,"");
              if (iVar10 < 1) goto LAB_00556040;
              iVar10 = i2a_ASN1_OBJECT(out,*ppAVar11);
              if (iVar10 < 1) {
                iStack_98 = 0;
                pcStack_88 = (char *)0x0;
                ppcStack_8c = (char **)0x0;
                iStack_84 = 1;
              }
              else {
                if (ppAVar11[1] == (ASN1_OBJECT *)0x0) {
                  iStack_84 = (*(code *)PTR_sk_num_006a6e2c)(ppAVar11[2]);
                  iStack_98 = 0;
                  goto LAB_005563e0;
                }
                iStack_98 = 0;
                iStack_84 = 1;
                pcStack_88 = ppAVar11[2]->sn;
                ppcStack_8c = ppAVar11[2]->ln;
              }
              while( true ) {
                iVar10 = 0x19 - iVar10;
                if (0 < iVar10) {
                  do {
                    iVar14 = (*(code *)PTR_BIO_write_006a6e14)(out,&DAT_0063eb84,1);
                    iVar10 = iVar10 + -1;
                    if (iVar14 != 1) goto LAB_00556040;
                  } while (iVar10 != 0);
                }
                iVar14 = (*(code *)PTR_BIO_puts_006a6f58)(out,":");
                if (iVar14 < 1) goto LAB_00556040;
                if ((pcStack_88 + -0x13 < (char *)0x2) || (pcStack_88 == (char *)0x16)) {
                  pcVar18 = (char *)(*(code *)PTR_BIO_write_006a6e14)
                                              (out,ppcStack_8c[2],*ppcStack_8c);
                  if (pcVar18 != *ppcStack_8c) goto LAB_00556040;
                  (*(code *)PTR_BIO_puts_006a6f58)(out,"\n");
                }
                else {
                  (*(code *)PTR_BIO_puts_006a6f58)(out,"unable to print attribute\n");
                }
                iStack_98 = iStack_98 + 1;
                if (iStack_84 <= iStack_98) break;
LAB_005563e0:
                ppcVar15 = (char **)(*(code *)PTR_sk_value_006a6e24)(ppAVar11[2],iStack_98);
                pcStack_88 = *ppcVar15;
                ppcStack_8c = (char **)ppcVar15[1];
              }
            }
          }
        }
        iVar4 = (*(code *)PTR_X509_REQ_get_extensions_006a7bb0)(in);
        if (iVar4 == 0) {
LAB_00556350:
          iVar4 = X509_signature_print(out,(X509_ALGOR *)in[1],(ASN1_STRING *)in[2]);
          if (iVar4 != 0) {
            pEVar19 = (EVP_PKEY *)0x1;
            goto LAB_00556068;
          }
        }
        else {
          (*(code *)PTR_BIO_printf_006a6e38)(out,"%8sRequested Extensions:\n","");
          iVar10 = 0;
          do {
            iVar14 = (*(code *)PTR_sk_num_006a6e2c)(iVar4);
            if (iVar14 <= iVar10) {
              (*(code *)PTR_sk_pop_free_006a7058)(iVar4,PTR_X509_EXTENSION_free_006a7168);
              goto LAB_00556350;
            }
            iVar14 = (*(code *)PTR_sk_value_006a6e24)(iVar4,iVar10);
            iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_00669a00,"");
            if (iVar13 < 1) break;
            a_00 = (ASN1_OBJECT *)(*(code *)PTR_X509_EXTENSION_get_object_006a7bb4)(iVar14);
            i2a_ASN1_OBJECT(out,a_00);
            iVar13 = (*(code *)PTR_X509_EXTENSION_get_critical_006a8d4c)(iVar14);
            pcVar18 = "";
            if (iVar13 != 0) {
              pcVar18 = "critical";
            }
            iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(out,": %s\n",pcVar18);
            if (iVar13 < 1) break;
            iVar13 = (*(code *)PTR_X509V3_EXT_print_006a8d50)(out,iVar14,0,0x10);
            iVar10 = iVar10 + 1;
            if (iVar13 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_00669a40,"");
              ASN1_STRING_print(out,*(ASN1_STRING **)(iVar14 + 8));
            }
            iVar14 = (*(code *)PTR_BIO_write_006a6e14)(out,"\n",1);
          } while (0 < iVar14);
        }
      }
    }
  }
LAB_00556040:
  pEVar19 = (EVP_PKEY *)0x0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x79,7,"t_req.c",0xf7);
LAB_00556068:
  (*(code *)PTR_BIO_free_006a6e70)(out);
  return pEVar19;
}

