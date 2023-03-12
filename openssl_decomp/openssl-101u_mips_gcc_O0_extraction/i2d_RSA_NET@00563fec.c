
int i2d_RSA_NET(RSA *a,uchar **pp,cb *cb,int sgckey)

{
  undefined *puVar1;
  undefined4 uVar2;
  ASN1_TYPE *pAVar3;
  int iVar4;
  ASN1_STRING *pAVar5;
  undefined4 *puVar6;
  ASN1_STRING *pAVar7;
  uchar **out;
  int iVar8;
  undefined1 *puVar9;
  uchar **out_00;
  undefined1 *puVar10;
  undefined4 *unaff_s0;
  ASN1_STRING **unaff_s1;
  undefined *unaff_s2;
  undefined *unaff_s3;
  undefined4 unaff_s4;
  RSA *unaff_s5;
  RSA *pRVar11;
  int *piVar12;
  undefined4 unaff_s6;
  int *unaff_s7;
  code *pcVar13;
  undefined *puVar14;
  undefined *puVar15;
  uchar **unaff_s8;
  code *unaff_retaddr;
  undefined auStackX_0 [16];
  
  puVar9 = (undefined1 *)pp;
  do {
    out = (uchar **)puVar9;
    puVar1 = PTR___stack_chk_guard_006a9ae8;
    *(undefined **)((int)register0x00000074 + -0x20) = unaff_s2;
    *(undefined **)((int)register0x00000074 + -0x1c) = unaff_s3;
    unaff_s3 = (undefined *)((int)register0x00000074 + -0x1f8);
    *(uchar ***)((int)register0x00000074 + -8) = unaff_s8;
    *(int **)((int)register0x00000074 + -0xc) = unaff_s7;
    *(RSA **)((int)register0x00000074 + -0x14) = unaff_s5;
    *(undefined **)((int)register0x00000074 + -0x220) = &_gp;
    *(code **)((int)register0x00000074 + -4) = unaff_retaddr;
    *(undefined4 *)((int)register0x00000074 + -0x10) = unaff_s6;
    *(undefined4 *)((int)register0x00000074 + -0x18) = unaff_s4;
    *(ASN1_STRING ***)((int)register0x00000074 + -0x24) = unaff_s1;
    *(undefined4 **)((int)register0x00000074 + -0x28) = unaff_s0;
    *(int *)((int)register0x00000074 + 0xc) = sgckey;
    *(undefined4 *)((int)register0x00000074 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006a9ae8
    ;
    puVar9 = (undefined1 *)out;
    puVar10 = cb;
    (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(unaff_s3);
    puVar14 = *(undefined **)((int)register0x00000074 + -0x220);
    unaff_s5 = a;
    unaff_s7 = (int *)cb;
    if (a == (RSA *)0x0) {
      pRVar11 = (RSA *)0x0;
    }
    else {
      unaff_s4 = 0x690000;
      unaff_s6 = 0x690000;
      unaff_s0 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)NETSCAPE_PKEY_it);
      puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
      if (unaff_s0 == (undefined4 *)0x0) {
LAB_00564260:
        unaff_s1 = (ASN1_STRING **)0x0;
        pRVar11 = (RSA *)0x0;
      }
      else {
        unaff_s1 = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
        if (unaff_s1 == (ASN1_STRING **)0x0) goto LAB_00564260;
        pcVar13 = *(code **)(puVar15 + -0x7ca0);
        *unaff_s0 = 0;
        *(undefined4 *)((int)register0x00000074 + -0x214) = unaff_s0[1];
        uVar2 = (*pcVar13)(6);
        *(undefined4 *)((int)register0x00000074 + -0x218) = unaff_s0[1];
        **(undefined4 **)((int)register0x00000074 + -0x214) = uVar2;
        pAVar3 = ASN1_TYPE_new();
        puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
        *(ASN1_TYPE **)(*(int *)((int)register0x00000074 + -0x218) + 4) = pAVar3;
        if (pAVar3 == (ASN1_TYPE *)0x0) {
LAB_005642e0:
          pRVar11 = (RSA *)0x0;
        }
        else {
          iVar4 = unaff_s0[1];
          pcVar13 = *(code **)(puVar15 + -0x6020);
          *(undefined4 *)((int)register0x00000074 + -0x210) = 5;
          **(undefined4 **)(iVar4 + 4) = 5;
          uVar2 = (*pcVar13)(a,0);
          puVar6 = (undefined4 *)unaff_s0[2];
          *(undefined4 *)((int)register0x00000074 + -0x218) = uVar2;
          *puVar6 = uVar2;
          iVar4 = ASN1_item_i2d((ASN1_VALUE *)unaff_s0,(uchar **)0x0,(ASN1_ITEM *)NETSCAPE_PKEY_it);
          pAVar7 = unaff_s1[1];
          *(int *)((int)register0x00000074 + -0x20c) = iVar4;
          pAVar5 = *unaff_s1;
          iVar8 = pAVar7->length;
          puVar10 = (undefined1 *)pAVar7->type;
          pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x7ca0);
          *(int *)puVar10 = iVar4;
          *(int *)((int)register0x00000074 + -0x214) = iVar8;
          pAVar5->length = 0xb;
          uVar2 = (*pcVar13)(5);
          iVar4 = unaff_s1[1]->length;
          **(undefined4 **)((int)register0x00000074 + -0x214) = uVar2;
          *(int *)((int)register0x00000074 + -0x214) = iVar4;
          pAVar3 = ASN1_TYPE_new();
          puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
          *(ASN1_TYPE **)(*(int *)((int)register0x00000074 + -0x214) + 4) = pAVar3;
          if (pAVar3 == (ASN1_TYPE *)0x0) goto LAB_005642e0;
          **(undefined4 **)(unaff_s1[1]->length + 4) =
               *(undefined4 *)((int)register0x00000074 + -0x210);
          if (out == (uchar **)0x0) {
            puVar10 = NETSCAPE_ENCRYPTED_PKEY_it;
            iVar4 = ASN1_item_i2d((ASN1_VALUE *)unaff_s1,(uchar **)0x0,
                                  (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
            *(int *)((int)register0x00000074 + -0x218) = iVar4;
            ASN1_item_free((ASN1_VALUE *)unaff_s0,(ASN1_ITEM *)NETSCAPE_PKEY_it);
            puVar9 = NETSCAPE_ENCRYPTED_PKEY_it;
            ASN1_item_free((ASN1_VALUE *)unaff_s1,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
            puVar14 = *(undefined **)((int)register0x00000074 + -0x220);
            pRVar11 = *(RSA **)((int)register0x00000074 + -0x218);
            goto LAB_005642a4;
          }
          pcVar13 = *(code **)(puVar15 + -0x7dd8);
          *(char **)((int)register0x00000074 + -0x214) = "encrypt";
          iVar4 = (*pcVar13)(*(undefined4 *)((int)register0x00000074 + -0x218),"n_pkey.c",0xab);
          *(int *)((int)register0x00000074 + -0x1fc) = iVar4;
          if (iVar4 == 0) {
            puVar10 = &DAT_00000041;
            pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x6eac);
            iVar4 = *(int *)((int)register0x00000074 + -0x214) + -0x5c68;
            uVar2 = 0xac;
LAB_00564248:
            *(undefined4 *)((int)register0x00000074 + -0x230) = uVar2;
            pRVar11 = (RSA *)0x0;
            (*pcVar13)(0xd,0xa2,puVar10,iVar4);
            puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
          }
          else {
            iVar8 = unaff_s0[2];
            pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x6020);
            *(undefined **)((int)register0x00000074 + -0x210) =
                 (undefined *)((int)register0x00000074 + -0x1fc);
            *(int *)(iVar8 + 8) = iVar4;
            (*pcVar13)(a,(undefined *)((int)register0x00000074 + -0x1fc));
            iVar4 = (**(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x7dd8))
                              (*(undefined4 *)((int)register0x00000074 + -0x20c),
                               *(int *)((int)register0x00000074 + -0x214) + -0x5c68,0xb4);
            *(int *)((int)register0x00000074 + -0x1fc) = iVar4;
            if (iVar4 == 0) {
              puVar10 = &DAT_00000041;
              pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x6eac);
              iVar4 = *(int *)((int)register0x00000074 + -0x214) + -0x5c68;
              uVar2 = 0xb5;
              goto LAB_00564248;
            }
            iVar4 = ASN1_STRING_set(*unaff_s1,"private-key",-1);
            if (iVar4 == 0) {
              puVar10 = &DAT_00000041;
              pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x6eac);
              iVar4 = *(int *)((int)register0x00000074 + -0x214) + -0x5c68;
              uVar2 = 0xba;
              goto LAB_00564248;
            }
            piVar12 = (int *)((int)register0x00000074 + -300);
            out_00 = *(uchar ***)((int)register0x00000074 + -0x210);
            *(undefined4 *)(unaff_s1[1]->type + 8) =
                 *(undefined4 *)((int)register0x00000074 + -0x1fc);
            ASN1_item_i2d((ASN1_VALUE *)unaff_s0,out_00,(ASN1_ITEM *)NETSCAPE_PKEY_it);
            (**(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x7d6c))
                      (*(undefined4 *)(unaff_s0[2] + 8),
                       *(undefined4 *)((int)register0x00000074 + -0x218));
            if ((int *)cb == (int *)0x0) {
              cb = (cb *)*(int **)(*(int *)((int)register0x00000074 + -0x220) + -0x7b68);
            }
            iVar4 = (*cb)(piVar12,0x100,"Enter Private Key password:",1);
            *(int *)((int)register0x00000074 + -0x204) = iVar4;
            if (iVar4 != 0) {
              puVar10 = (undefined1 *)0x67;
              pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x6eac);
              iVar4 = *(int *)((int)register0x00000074 + -0x214) + -0x5c68;
              uVar2 = 199;
              goto LAB_00564248;
            }
            cb = (cb *)(**(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x53bc))(piVar12);
            puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
            *(cb **)((int)register0x00000074 + -0x204) = cb;
            if (*(int *)((int)register0x00000074 + 0xc) != 0) {
              uVar2 = (**(code **)(puVar15 + -0x7d18))();
              *(undefined4 *)((int)register0x00000074 + -0x22c) = 0;
              *(undefined4 *)((int)register0x00000074 + -0x230) = uVar2;
              puVar10 = (undefined1 *)piVar12;
              iVar4 = (**(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x73cc))
                                (piVar12,cb,piVar12,0);
              puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
              if (iVar4 == 0) goto LAB_005642e0;
              *(undefined4 *)((int)register0x00000074 + -0x204) = 0x1a;
              *(undefined4 *)((int)register0x00000074 + -0x11c) = s_SGCKEYSALT_0066a3a4._0_4_;
              *(undefined4 *)((int)register0x00000074 + -0x118) = s_SGCKEYSALT_0066a3a4._4_4_;
              *(undefined2 *)((int)register0x00000074 + -0x114) = s_SGCKEYSALT_0066a3a4._8_2_;
            }
            cb = (cb *)((int)register0x00000074 + -0x16c);
            uVar2 = (**(code **)(puVar15 + -0x69d8))();
            pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x7d18);
            *(undefined4 *)((int)register0x00000074 + -0x218) = uVar2;
            uVar2 = (*pcVar13)();
            puVar10 = (undefined1 *)0x0;
            *(undefined4 *)((int)register0x00000074 + -0x224) = 0;
            *(cb **)((int)register0x00000074 + -0x228) = cb;
            *(undefined4 *)((int)register0x00000074 + -0x22c) = 1;
            pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x7894);
            *(undefined4 *)((int)register0x00000074 + -0x230) =
                 *(undefined4 *)((int)register0x00000074 + -0x204);
            iVar4 = (*pcVar13)(*(undefined4 *)((int)register0x00000074 + -0x218),uVar2,0,piVar12);
            puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
            if (iVar4 == 0) goto LAB_005642e0;
            (**(code **)(puVar15 + -0x7d6c))(piVar12,0x100);
            pcVar13 = *(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x69d8);
            *(undefined4 *)((int)register0x00000074 + -0x1fc) =
                 *(undefined4 *)(unaff_s1[1]->type + 8);
            uVar2 = (*pcVar13)();
            puVar10 = (undefined1 *)0x0;
            *(undefined4 *)((int)register0x00000074 + -0x230) = 0;
            iVar4 = (**(code **)(*(int *)((int)register0x00000074 + -0x220) + -0x7348))
                              (unaff_s3,uVar2,0,cb);
            puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
            if (iVar4 == 0) goto LAB_005642e0;
            puVar10 = (undefined1 *)((int)register0x00000074 + -0x204);
            pcVar13 = *(code **)(puVar15 + -0x7340);
            *(undefined4 *)((int)register0x00000074 + -0x230) =
                 *(undefined4 *)((int)register0x00000074 + -0x20c);
            iVar4 = (*pcVar13)(unaff_s3,*(undefined4 *)((int)register0x00000074 + -0x1fc));
            puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
            if (iVar4 == 0) goto LAB_005642e0;
            puVar10 = (undefined1 *)((int)register0x00000074 + -0x200);
            iVar4 = (**(code **)(puVar15 + -0x7344))
                              (unaff_s3,*(int *)((int)register0x00000074 + -0x1fc) +
                                        *(int *)((int)register0x00000074 + -0x204));
            puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
            if (iVar4 == 0) goto LAB_005642e0;
            puVar10 = NETSCAPE_ENCRYPTED_PKEY_it;
            pRVar11 = (RSA *)ASN1_item_i2d((ASN1_VALUE *)unaff_s1,out,
                                           (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
            puVar15 = *(undefined **)((int)register0x00000074 + -0x220);
          }
        }
      }
      (**(code **)(puVar15 + -0x736c))(unaff_s3);
      ASN1_item_free((ASN1_VALUE *)unaff_s1,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
      puVar9 = NETSCAPE_PKEY_it;
      ASN1_item_free((ASN1_VALUE *)unaff_s0,(ASN1_ITEM *)NETSCAPE_PKEY_it);
      puVar14 = *(undefined **)((int)register0x00000074 + -0x220);
      unaff_s5 = pRVar11;
      unaff_s7 = (int *)cb;
    }
LAB_005642a4:
    a = *(RSA **)((int)register0x00000074 + -0x2c);
    if (a == *(RSA **)puVar1) {
      return (int)pRVar11;
    }
    unaff_retaddr = i2d_Netscape_RSA;
    (**(code **)(puVar14 + -0x5330))();
    sgckey = 0;
    cb = (cb *)puVar10;
    unaff_s2 = puVar1;
    register0x00000074 = (BADSPACEBASE *)((int)register0x00000074 + -0x240);
    unaff_s8 = out;
  } while( true );
}

