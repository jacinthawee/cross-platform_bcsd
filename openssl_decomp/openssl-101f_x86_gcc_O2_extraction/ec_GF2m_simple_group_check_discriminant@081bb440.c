
bool ec_GF2m_simple_group_check_discriminant(int param_1,BN_CTX *param_2)

{
  BIGNUM *pBVar1;
  int iVar2;
  BN_CTX *c;
  bool bVar3;
  
  c = (BN_CTX *)0x0;
  if ((param_2 == (BN_CTX *)0x0) && (param_2 = BN_CTX_new(), c = param_2, param_2 == (BN_CTX *)0x0))
  {
    ERR_put_error(0x10,0x9f,0x41,"ec2_smpl.c",0x115);
    return false;
  }
  BN_CTX_start(param_2);
  pBVar1 = BN_CTX_get(param_2);
  if ((pBVar1 == (BIGNUM *)0x0) ||
     (iVar2 = BN_GF2m_mod_arr(pBVar1,param_1 + 0x88,param_1 + 0x5c), iVar2 == 0)) {
    bVar3 = false;
  }
  else {
    bVar3 = pBVar1->top != 0;
  }
  BN_CTX_end(param_2);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return bVar3;
}
