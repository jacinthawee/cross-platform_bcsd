
int RSA_verify(int type,uchar *m,uint m_length,uchar *sigbuf,uint siglen,RSA *rsa)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  uchar *unaff_s7;
  _func_1627 *p_Var9;
  int unaff_s8;
  uchar *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (((rsa->flags & 0x40U) == 0) || (p_Var9 = rsa->meth->rsa_verify, p_Var9 == (_func_1627 *)0x0))
  {
    uVar3 = RSA_size(rsa);
    if (siglen == uVar3) {
      unaff_s8 = 0x660000;
      unaff_s7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(siglen,"rsa_sign.c",0xbd);
      if (unaff_s7 != (uchar *)0x0) {
        if (type == 0x72) {
          if (m_length == 0x24) {
            iVar2 = RSA_public_decrypt(siglen,sigbuf,unaff_s7,rsa,1);
            if (iVar2 < 1) goto LAB_005112c8;
            if ((iVar2 == 0x24) &&
               (iVar2 = (*(code *)PTR_memcmp_006aabd8)(unaff_s7,m,0x24), iVar2 == 0)) {
              iVar2 = 1;
              goto LAB_005112cc;
            }
            uVar8 = 0x68;
            uVar5 = 0xde;
          }
          else {
            uVar8 = 0x83;
            uVar5 = 0xc4;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,uVar8,"rsa_sign.c",uVar5);
        }
        else {
          sigbuf = (uchar *)RSA_public_decrypt(siglen,sigbuf,unaff_s7,rsa,1);
          if (0 < (int)sigbuf) {
            if (type == 0x5f) {
              iVar2 = 0;
              if (sigbuf != &DAT_00000012) goto LAB_00511204;
              if (*unaff_s7 != '\x04') goto LAB_00511204;
              if (unaff_s7[1] != '\x10') goto LAB_00511204;
              iVar2 = (*(code *)PTR_memcmp_006aabd8)(m,unaff_s7 + 2,0x10);
              if (iVar2 != 0) goto LAB_00511514;
              iVar2 = 1;
              goto LAB_00511204;
            }
            iVar2 = 0;
            goto LAB_00511204;
          }
        }
LAB_005112c8:
        iVar2 = 0;
        goto LAB_005112cc;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,0x41,"rsa_sign.c",0xc0);
      iVar2 = 0;
    }
    else {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,0x77,"rsa_sign.c",0xaf);
      iVar2 = 0;
    }
  }
  else {
    iVar2 = (*p_Var9)(type,m,m_length,sigbuf,siglen,rsa);
  }
  do {
    if (local_2c == *(int *)puVar1) {
      return iVar2;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00511514:
    iVar2 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,0x68,unaff_s8 + 0x7650,0xd6);
LAB_00511204:
    local_30 = unaff_s7;
    piVar4 = (int *)(*(code *)PTR_d2i_X509_SIG_006a985c)(0,&local_30,sigbuf);
    if (piVar4 != (int *)0x0) {
      sigbuf = unaff_s7 + (int)sigbuf;
      if (local_30 == sigbuf) {
        puVar6 = (undefined4 *)*piVar4;
        if (puVar6[1] != 0) {
          iVar7 = (*(code *)PTR_ASN1_TYPE_get_006a85b0)();
          if (iVar7 != 5) {
            uVar8 = 0x68;
            uVar5 = 0xf2;
            goto LAB_00511244;
          }
          puVar6 = (undefined4 *)*piVar4;
        }
        iVar7 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar6);
        if (type != iVar7) {
          if (type == 4) {
            if (iVar7 == 8) goto LAB_00511484;
          }
          else if ((type == 3) && (iVar7 == 7)) {
LAB_00511484:
            (*(code *)PTR_fwrite_006aab7c)
                      ("signature has problems, re-make with post SSLeay045\n",1,0x34,
                       *(undefined4 *)PTR_stderr_006aac00);
            goto LAB_005114b0;
          }
          uVar8 = 100;
          uVar5 = 0x10d;
          goto LAB_00511244;
        }
LAB_005114b0:
        if ((m_length != *(uint *)piVar4[1]) ||
           (iVar7 = (*(code *)PTR_memcmp_006aabd8)(m,((uint *)piVar4[1])[2],m_length), iVar7 != 0))
        {
          uVar8 = 0x68;
          uVar5 = 0x123;
          goto LAB_00511244;
        }
        iVar2 = 1;
      }
      else {
        uVar8 = 0x68;
        uVar5 = 0xe9;
LAB_00511244:
        (*(code *)PTR_ERR_put_error_006a9030)(4,0x91,uVar8,unaff_s8 + 0x7650,uVar5);
      }
      (*(code *)PTR_X509_SIG_free_006a8d98)(piVar4);
    }
LAB_005112cc:
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s7,siglen);
    (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s7);
  } while( true );
}

