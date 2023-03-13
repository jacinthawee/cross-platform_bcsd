
EVP_PKEY * d2i_PrivateKey(int type,EVP_PKEY **a,uchar **pp,long length)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  EVP_PKEY *pEVar5;
  EVP_PKEY *pEVar6;
  ASN1_SEQUENCE_ANY *pAVar7;
  PKCS8_PRIV_KEY_INFO *pPVar8;
  undefined4 uVar9;
  BIO *out;
  int *piVar10;
  int iVar11;
  ASN1_OBJECT **ppAVar12;
  undefined4 uVar13;
  int iVar14;
  ASN1_OBJECT *a_00;
  int iVar15;
  char **ppcVar16;
  byte *pbVar17;
  EVP_PKEY **ppEVar18;
  uchar **in;
  uchar **in_00;
  byte *pbVar19;
  long len;
  char *pcVar20;
  uchar *puVar21;
  code *pcVar22;
  int iStack_e0;
  char **ppcStack_d4;
  char *pcStack_d0;
  int iStack_cc;
  uchar *puStack_74;
  uchar *puStack_70;
  int iStack_6c;
  EVP_PKEY *pEStack_64;
  EVP_PKEY **ppEStack_60;
  undefined *puStack_5c;
  uchar **ppuStack_58;
  EVP_PKEY *pEStack_54;
  int iStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined *local_30;
  uchar *local_28;
  EVP_PKEY **local_24;
  
  puStack_5c = PTR___stack_chk_guard_006a9ae8;
  local_28 = *pp;
  local_30 = &_gp;
  local_24 = *(EVP_PKEY ***)PTR___stack_chk_guard_006a9ae8;
  if ((a == (EVP_PKEY **)0x0) || (pEStack_64 = *a, pEStack_64 == (EVP_PKEY *)0x0)) {
    pEStack_64 = EVP_PKEY_new();
    if (pEStack_64 != (EVP_PKEY *)0x0) goto LAB_005557f0;
    len = 6;
    local_38 = 0x4f;
    in = (uchar **)0x9a;
    (**(code **)(local_30 + -0x6eac))(0xd,0x9a,6,"d2i_pr.c");
    pEVar6 = (EVP_PKEY *)0x0;
  }
  else {
    if (pEStack_64->engine != (ENGINE *)0x0) {
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
      pEStack_64->engine = (ENGINE *)0x0;
    }
LAB_005557f0:
    iVar3 = EVP_PKEY_set_type(pEStack_64,type);
    if (iVar3 == 0) {
      pcVar22 = *(code **)(local_30 + -0x6eac);
      len = 0xa3;
      local_38 = 0x5d;
LAB_005558c0:
      in = (uchar **)0x9a;
      (*pcVar22)(0xd,0x9a,len,"d2i_pr.c");
      pEVar5 = (EVP_PKEY *)length;
    }
    else {
      pEVar4 = pEStack_64->ameth;
      in = &local_28;
      if (*(code **)(pEVar4 + 0x5c) != (code *)0x0) {
        len = length;
        iVar3 = (**(code **)(pEVar4 + 0x5c))(pEStack_64);
        pEVar6 = pEStack_64;
        if (iVar3 == 0) {
          pEVar4 = pEStack_64->ameth;
          goto LAB_00555830;
        }
LAB_00555894:
        *pp = local_28;
        pEStack_64 = pEVar6;
        if (a != (EVP_PKEY **)0x0) {
          *a = pEVar6;
        }
        goto LAB_005558f8;
      }
LAB_00555830:
      in = &local_28;
      if (*(int *)(pEVar4 + 0x24) == 0) {
        pcVar22 = *(code **)(local_30 + -0x6eac);
        len = 0xd;
        local_38 = 0x70;
        goto LAB_005558c0;
      }
      pEVar5 = (EVP_PKEY *)d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,in,length);
      len = length;
      if (pEVar5 != (EVP_PKEY *)0x0) {
        pEVar6 = EVP_PKCS82PKEY((PKCS8_PRIV_KEY_INFO *)pEVar5);
        PKCS8_PRIV_KEY_INFO_free((PKCS8_PRIV_KEY_INFO *)pEVar5);
        len = length;
        pEVar5 = pEVar6;
        if (pEVar6 != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(pEStack_64);
          len = length;
          length = (long)pEVar6;
          goto LAB_00555894;
        }
      }
    }
    length = (long)pEVar5;
    if ((a == (EVP_PKEY **)0x0) || (pEVar6 = (EVP_PKEY *)0x0, pEStack_64 != *a)) {
      EVP_PKEY_free(pEStack_64);
      pEVar6 = (EVP_PKEY *)0x0;
    }
  }
LAB_005558f8:
  if (local_24 == *(EVP_PKEY ***)puStack_5c) {
    return pEVar6;
  }
  pcStack_4c = d2i_AutoPrivateKey;
  ppEVar18 = local_24;
  (**(code **)(local_30 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_74 = *in;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppEStack_60 = a;
  ppuStack_58 = pp;
  pEStack_54 = (EVP_PKEY *)length;
  iStack_50 = type;
  pAVar7 = d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&puStack_74,len);
  puStack_74 = *in;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(pAVar7);
  if (iVar3 == 6) {
    iVar3 = 0x74;
LAB_00555a58:
    (*(code *)PTR_sk_pop_free_006a7058)(pAVar7,PTR_ASN1_TYPE_free_006a7498);
    puStack_70 = *in;
    if ((ppEVar18 == (EVP_PKEY **)0x0) || (pEVar6 = *ppEVar18, pEVar6 == (EVP_PKEY *)0x0)) {
      pEVar6 = EVP_PKEY_new();
      if (pEVar6 != (EVP_PKEY *)0x0) goto LAB_00555aa0;
      in_00 = (uchar **)0x9a;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x9a,6,"d2i_pr.c",0x4f);
      pEVar5 = (EVP_PKEY *)0x0;
    }
    else {
      if (pEVar6->engine != (ENGINE *)0x0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
        pEVar6->engine = (ENGINE *)0x0;
      }
LAB_00555aa0:
      iVar3 = EVP_PKEY_set_type(pEVar6,iVar3);
      if (iVar3 == 0) {
        uVar13 = 0xa3;
        uVar9 = 0x5d;
LAB_00555b78:
        in_00 = (uchar **)0x9a;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x9a,uVar13,"d2i_pr.c",uVar9);
      }
      else {
        pEVar4 = pEVar6->ameth;
        in_00 = &puStack_70;
        if (*(code **)(pEVar4 + 0x5c) != (code *)0x0) {
          iVar3 = (**(code **)(pEVar4 + 0x5c))(pEVar6,in_00,len);
          pEVar5 = pEVar6;
          if (iVar3 == 0) {
            pEVar4 = pEVar6->ameth;
            goto LAB_00555ae0;
          }
LAB_00555b44:
          *in = puStack_70;
          if (ppEVar18 != (EVP_PKEY **)0x0) goto LAB_00555b50;
          goto LAB_00555bb0;
        }
LAB_00555ae0:
        in_00 = &puStack_70;
        if (*(int *)(pEVar4 + 0x24) == 0) {
          uVar13 = 0xd;
          uVar9 = 0x70;
          goto LAB_00555b78;
        }
        pPVar8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,in_00,len);
        if (pPVar8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
          pEVar5 = EVP_PKCS82PKEY(pPVar8);
          PKCS8_PRIV_KEY_INFO_free(pPVar8);
          if (pEVar5 != (EVP_PKEY *)0x0) {
            EVP_PKEY_free(pEVar6);
            goto LAB_00555b44;
          }
        }
      }
      if ((ppEVar18 == (EVP_PKEY **)0x0) || (pEVar5 = (EVP_PKEY *)0x0, pEVar6 != *ppEVar18)) {
        EVP_PKEY_free(pEVar6);
        pEVar5 = (EVP_PKEY *)0x0;
      }
    }
  }
  else {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(pAVar7);
    if (iVar3 == 4) {
      iVar3 = 0x198;
      goto LAB_00555a58;
    }
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(pAVar7);
    if (iVar3 != 3) {
      iVar3 = 6;
      goto LAB_00555a58;
    }
    pPVar8 = d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,&puStack_74,len);
    in_00 = (uchar **)PTR_ASN1_TYPE_free_006a7498;
    (*(code *)PTR_sk_pop_free_006a7058)(pAVar7);
    if (pPVar8 == (PKCS8_PRIV_KEY_INFO *)0x0) {
      in_00 = (uchar **)0xcf;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xcf,0xa7,"d2i_pr.c",0xa1);
      pEVar5 = (EVP_PKEY *)0x0;
      goto LAB_00555bb0;
    }
    pEVar5 = EVP_PKCS82PKEY(pPVar8);
    PKCS8_PRIV_KEY_INFO_free(pPVar8);
    if (pEVar5 == (EVP_PKEY *)0x0) {
      pEVar5 = (EVP_PKEY *)0x0;
      goto LAB_00555bb0;
    }
    *in = puStack_74;
    if (ppEVar18 == (EVP_PKEY **)0x0) goto LAB_00555bb0;
LAB_00555b50:
    *ppEVar18 = pEVar5;
  }
LAB_00555bb0:
  if (iStack_6c == *(int *)puVar2) {
    return pEVar5;
  }
  iVar3 = iStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar9 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  out = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar9);
  if (out == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7a,7,"t_req.c",0x50);
    return (EVP_PKEY *)0x0;
  }
  (*(code *)PTR_BIO_ctrl_006a6e18)(out,0x6a,0,iVar3);
  puVar21 = *in_00;
  iVar3 = (*(code *)PTR_BIO_write_006a6e14)(out,"Certificate Request:\n",0x15);
  if ((0 < iVar3) && (iVar3 = (*(code *)PTR_BIO_write_006a6e14)(out,"    Data:\n",10), 0 < iVar3)) {
    piVar10 = *(int **)(puVar21 + 0xc);
    if (piVar10[1] == 0x102) {
      pcVar20 = "-";
    }
    else {
      pcVar20 = "";
    }
    if (*piVar10 < 1) {
      iVar3 = 0;
    }
    else {
      pbVar17 = (byte *)piVar10[2];
      iVar3 = 0;
      pbVar19 = pbVar17 + *piVar10;
      do {
        bVar1 = *pbVar17;
        pbVar17 = pbVar17 + 1;
        iVar3 = (uint)bVar1 + iVar3 * 0x100;
      } while (pbVar19 != pbVar17);
    }
    iVar3 = (*(code *)PTR_BIO_printf_006a6e38)
                      (out,"%8sVersion: %s%lu (%s0x%lx)\n","",pcVar20,iVar3,pcVar20,iVar3);
    if (((((0 < iVar3) &&
          (iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(out,"        Subject:%c",0x20), 0 < iVar3)) &&
         (iVar3 = X509_NAME_print_ex(out,*(X509_NAME **)(puVar21 + 0x10),0x10,0), -1 < iVar3)) &&
        ((iVar3 = (*(code *)PTR_BIO_write_006a6e14)(out,"\n",1), 0 < iVar3 &&
         (iVar3 = (*(code *)PTR_BIO_write_006a6e14)(out,"        Subject Public Key Info:\n",0x21),
         0 < iVar3)))) &&
       ((iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(out,"%12sPublic Key Algorithm: ",""), 0 < iVar3
        && ((iVar3 = i2a_ASN1_OBJECT(out,*(ASN1_OBJECT **)**(undefined4 **)(puVar21 + 0x14)),
            0 < iVar3 && (iVar3 = (*(code *)PTR_BIO_puts_006a6f58)(out,"\n"), 0 < iVar3)))))) {
      pEVar6 = (EVP_PKEY *)(*(code *)PTR_X509_REQ_get_pubkey_006a6ef4)(in_00);
      if (pEVar6 == (EVP_PKEY *)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)(out,"%12sUnable to load Public Key\n","");
        (*(code *)PTR_ERR_print_errors_006a6e40)(out);
      }
      else {
        EVP_PKEY_print_public(out,pEVar6,0x10,(ASN1_PCTX *)0x0);
        EVP_PKEY_free(pEVar6);
      }
      iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(out,"%8sAttributes:\n","");
      if (0 < iVar3) {
        uVar9 = *(undefined4 *)(*in_00 + 0x18);
        iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar9);
        if (iVar3 == 0) {
          iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(out,"%12sa0:00\n","");
          if (iVar3 < 1) goto LAB_00556040;
        }
        else {
          for (iVar3 = 0; iVar11 = (*(code *)PTR_sk_num_006a6e2c)(uVar9), iVar3 < iVar11;
              iVar3 = iVar3 + 1) {
            ppAVar12 = (ASN1_OBJECT **)(*(code *)PTR_sk_value_006a6e24)(uVar9,iVar3);
            uVar13 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*ppAVar12);
            iVar11 = (*(code *)PTR_X509_REQ_extension_nid_006a8d48)(uVar13);
            if (iVar11 == 0) {
              iVar11 = (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_00669a00,"");
              if (iVar11 < 1) goto LAB_00556040;
              iVar11 = i2a_ASN1_OBJECT(out,*ppAVar12);
              if (iVar11 < 1) {
                iStack_e0 = 0;
                pcStack_d0 = (char *)0x0;
                ppcStack_d4 = (char **)0x0;
                iStack_cc = 1;
              }
              else {
                if (ppAVar12[1] == (ASN1_OBJECT *)0x0) {
                  iStack_cc = (*(code *)PTR_sk_num_006a6e2c)(ppAVar12[2]);
                  iStack_e0 = 0;
                  goto LAB_005563e0;
                }
                iStack_e0 = 0;
                iStack_cc = 1;
                pcStack_d0 = ppAVar12[2]->sn;
                ppcStack_d4 = ppAVar12[2]->ln;
              }
              while( true ) {
                iVar11 = 0x19 - iVar11;
                if (0 < iVar11) {
                  do {
                    iVar15 = (*(code *)PTR_BIO_write_006a6e14)(out,&DAT_0063eb84,1);
                    iVar11 = iVar11 + -1;
                    if (iVar15 != 1) goto LAB_00556040;
                  } while (iVar11 != 0);
                }
                iVar15 = (*(code *)PTR_BIO_puts_006a6f58)(out,":");
                if (iVar15 < 1) goto LAB_00556040;
                if ((pcStack_d0 + -0x13 < (char *)0x2) || (pcStack_d0 == (char *)0x16)) {
                  pcVar20 = (char *)(*(code *)PTR_BIO_write_006a6e14)
                                              (out,ppcStack_d4[2],*ppcStack_d4);
                  if (pcVar20 != *ppcStack_d4) goto LAB_00556040;
                  (*(code *)PTR_BIO_puts_006a6f58)(out,"\n");
                }
                else {
                  (*(code *)PTR_BIO_puts_006a6f58)(out,"unable to print attribute\n");
                }
                iStack_e0 = iStack_e0 + 1;
                if (iStack_cc <= iStack_e0) break;
LAB_005563e0:
                ppcVar16 = (char **)(*(code *)PTR_sk_value_006a6e24)(ppAVar12[2],iStack_e0);
                pcStack_d0 = *ppcVar16;
                ppcStack_d4 = (char **)ppcVar16[1];
              }
            }
          }
        }
        iVar3 = (*(code *)PTR_X509_REQ_get_extensions_006a7bb0)(in_00);
        if (iVar3 == 0) {
LAB_00556350:
          iVar3 = X509_signature_print(out,(X509_ALGOR *)in_00[1],(ASN1_STRING *)in_00[2]);
          if (iVar3 != 0) {
            pEVar6 = (EVP_PKEY *)0x1;
            goto LAB_00556068;
          }
        }
        else {
          (*(code *)PTR_BIO_printf_006a6e38)(out,"%8sRequested Extensions:\n","");
          iVar11 = 0;
          do {
            iVar15 = (*(code *)PTR_sk_num_006a6e2c)(iVar3);
            if (iVar15 <= iVar11) {
              (*(code *)PTR_sk_pop_free_006a7058)(iVar3,PTR_X509_EXTENSION_free_006a7168);
              goto LAB_00556350;
            }
            iVar15 = (*(code *)PTR_sk_value_006a6e24)(iVar3,iVar11);
            iVar14 = (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_00669a00,"");
            if (iVar14 < 1) break;
            a_00 = (ASN1_OBJECT *)(*(code *)PTR_X509_EXTENSION_get_object_006a7bb4)(iVar15);
            i2a_ASN1_OBJECT(out,a_00);
            iVar14 = (*(code *)PTR_X509_EXTENSION_get_critical_006a8d4c)(iVar15);
            pcVar20 = "";
            if (iVar14 != 0) {
              pcVar20 = "critical";
            }
            iVar14 = (*(code *)PTR_BIO_printf_006a6e38)(out,": %s\n",pcVar20);
            if (iVar14 < 1) break;
            iVar14 = (*(code *)PTR_X509V3_EXT_print_006a8d50)(out,iVar15,0,0x10);
            iVar11 = iVar11 + 1;
            if (iVar14 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_00669a40,"");
              ASN1_STRING_print(out,*(ASN1_STRING **)(iVar15 + 8));
            }
            iVar15 = (*(code *)PTR_BIO_write_006a6e14)(out,"\n",1);
          } while (0 < iVar15);
        }
      }
    }
  }
LAB_00556040:
  pEVar6 = (EVP_PKEY *)0x0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x79,7,"t_req.c",0xf7);
LAB_00556068:
  (*(code *)PTR_BIO_free_006a6e70)(out);
  return pEVar6;
}

