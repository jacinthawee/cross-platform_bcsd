
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CERTIFICATEPOLICIES * CERTIFICATEPOLICIES_new(void)

{
  CERTIFICATEPOLICIES *pCVar1;
  
  pCVar1 = (CERTIFICATEPOLICIES *)ASN1_item_new((ASN1_ITEM *)CERTIFICATEPOLICIES_it);
  return pCVar1;
}

