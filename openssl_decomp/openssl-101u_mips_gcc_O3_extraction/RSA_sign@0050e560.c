
int RSA_sign(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  _func_1626 *p_Var8;
  code *pcVar9;
  undefined *local_60;
  uchar *local_58;
  int *local_54;
  uint *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44 [2];
  uint local_3c [2];
  uchar *local_34;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_60 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (((rsa->flags & 0x40U) != 0) && (p_Var8 = rsa->meth->rsa_sign, p_Var8 != (_func_1626 *)0x0)) {
    iVar3 = (*p_Var8)(type,m,m_length,sigret,siglen,rsa);
    goto LAB_0050e5f0;
  }
  if (type == 0x72) {
    if (m_length == 0x24) {
      iVar3 = RSA_size(rsa);
      if (0x2e < iVar3) {
        uVar5 = RSA_private_encrypt(0x24,m,sigret,rsa,1);
        iVar3 = 0;
        if (0 < (int)uVar5) {
          *siglen = uVar5;
          iVar3 = 1;
        }
        goto LAB_0050e5f0;
      }
      goto LAB_0050e7b8;
    }
    uVar7 = 0x83;
    uVar6 = 0x5d;
    pcVar9 = (code *)PTR_ERR_put_error_006a7f34;
  }
  else {
    local_54 = local_44;
    local_44[0] = (*(code *)PTR_OBJ_nid2obj_006a7140)(type);
    puVar1 = PTR_i2d_X509_SIG_006a8734;
    if (*local_54 == 0) {
      uVar7 = 0x75;
      uVar6 = 0x66;
      pcVar9 = (code *)PTR_ERR_put_error_006a7f34;
    }
    else {
      iVar3 = *(int *)(*local_54 + 0xc);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(4,0x75,0x74,"rsa_sign.c",0x6b);
        goto LAB_0050e5f0;
      }
      local_48 = 0;
      local_3c[0] = m_length;
      local_54[1] = (int)&local_4c;
      local_4c = 5;
      local_50 = local_3c;
      local_34 = m;
      iVar3 = (*(code *)puVar1)(&local_54,0);
      iVar4 = RSA_size(rsa);
      if (iVar3 < iVar4 + -10) {
        m_length = iVar4 + 1;
        m = (uchar *)(**(code **)(local_60 + -0x7dd8))(m_length,"rsa_sign.c",0x7e);
        if (m != (uchar *)0x0) {
          local_58 = m;
          (**(code **)(local_60 + -0x66ac))(&local_54,&local_58);
          uVar5 = RSA_private_encrypt(iVar3,m,sigret,rsa,1);
          if ((int)uVar5 < 1) goto LAB_0050e874;
          iVar3 = 1;
          *siglen = uVar5;
          goto LAB_0050e734;
        }
        iVar3 = 0;
        (**(code **)(local_60 + -0x6eac))(4,0x75,0x41,"rsa_sign.c",0x80);
        goto LAB_0050e5f0;
      }
LAB_0050e7b8:
      uVar7 = 0x70;
      uVar6 = 0x7a;
      pcVar9 = *(code **)(local_60 + -0x6eac);
    }
  }
  iVar3 = 0;
  (*pcVar9)(4,0x75,uVar7,"rsa_sign.c",uVar6);
LAB_0050e5f0:
  while( true ) {
    if (local_2c == *(int *)puVar2) break;
    (**(code **)(local_60 + -0x5330))();
LAB_0050e874:
    iVar3 = 0;
LAB_0050e734:
    (**(code **)(local_60 + -0x7d6c))(m,m_length);
    (**(code **)(local_60 + -0x7f58))(m);
  }
  return iVar3;
}

