
int DH_generate_key(DH *dh)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0810f67a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*dh->meth->generate_key)(dh);
  return iVar1;
}
