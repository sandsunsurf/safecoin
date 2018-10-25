/******************************************************************************
 * Copyright © 2014-2018 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

#include "safecoin_defs.h"

void safecoin_prefetch(FILE *fp);
uint32_t safecoin_heightstamp(int32_t height);
void safecoin_stateupdate(int32_t height,uint8_t notarypubs[][33],uint8_t numnotaries,uint8_t notaryid,uint256 txhash,uint64_t voutmask,uint8_t numvouts,uint32_t *pvals,uint8_t numpvals,int32_t kheight,uint32_t ktime,uint64_t opretvalue,uint8_t *opretbuf,uint16_t opretlen,uint16_t vout,uint256 MoM,int32_t MoMdepth);
void safecoin_init(int32_t height);
int32_t safecoin_MoMdata(int32_t *notarized_htp,uint256 *MoMp,uint256 *safetxidp,int32_t nHeight,uint256 *MoMoMp,int32_t *MoMoMoffsetp,int32_t *MoMoMdepthp,int32_t *safestartip,int32_t *safeendip);
int32_t safecoin_notarizeddata(int32_t nHeight,uint256 *notarized_hashp,uint256 *notarized_desttxidp);
char *safecoin_issuemethod(char *userpass,char *method,char *params,uint16_t port);
void safecoin_init(int32_t height);
int32_t safecoin_chosennotary(int32_t *notaryidp,int32_t height,uint8_t *pubkey33,uint32_t timestamp);
int32_t safecoin_isrealtime(int32_t *safeheightp);
uint64_t safecoin_paxtotal();
int32_t safecoin_longestchain();
uint64_t safecoin_maxallowed(int32_t baseid);
int32_t safecoin_bannedset(int32_t *indallvoutsp,uint256 *array,int32_t max);
bool pubkey2addr(char *destaddr,uint8_t *pubkey33);

pthread_mutex_t safecoin_mutex;

#define SAFECOIN_ELECTION_GAP 2000    //((ASSETCHAINS_SYMBOL[0] == 0) ? 2000 : 100)
#define SAFECOIN_ASSETCHAIN_MAXLEN 65

struct pax_transaction *PAX;
int32_t NUM_PRICES; uint32_t *PVALS;
struct knotaries_entry *Pubkeys;

struct safecoin_state SAFECOIN_STATES[34];

#define _COINBASE_MATURITY 100
int COINBASE_MATURITY = _COINBASE_MATURITY;//100;

int32_t SAFECOIN_MININGTHREADS = -1,IS_SAFECOIN_NOTARY,USE_EXTERNAL_PUBKEY,SAFECOIN_CHOSEN_ONE,ASSETCHAINS_SEED,SAFECOIN_ON_DEMAND,SAFECOIN_EXTERNAL_NOTARIES,SAFECOIN_PASSPORT_INITDONE,SAFECOIN_PAX,SAFECOIN_EXCHANGEWALLET,SAFECOIN_REWIND,SAFECOIN_CONNECTING = -1;
int32_t SAFECOIN_INSYNC,SAFECOIN_LASTMINED,prevSAFECOIN_LASTMINED,SAFECOIN_CCACTIVATE,JUMBLR_PAUSE = 1;
std::string NOTARY_PUBKEY,ASSETCHAINS_NOTARIES,ASSETCHAINS_OVERRIDE_PUBKEY,DONATION_PUBKEY;
uint8_t NOTARY_PUBKEY33[33],ASSETCHAINS_OVERRIDE_PUBKEY33[33],ASSETCHAINS_PUBLIC,ASSETCHAINS_PRIVATE;

char ASSETCHAINS_SYMBOL[SAFECOIN_ASSETCHAIN_MAXLEN],ASSETCHAINS_USERPASS[4096];
uint16_t ASSETCHAINS_P2PPORT,ASSETCHAINS_RPCPORT;
uint32_t ASSETCHAIN_INIT,ASSETCHAINS_CC,SAFECOIN_STOPAT,SAFECOIN_DPOWCONFS = 1;
uint32_t ASSETCHAINS_MAGIC = 2387029918;
uint64_t SAFECOIN_INTERESTSUM,SAFECOIN_WALLETBALANCE;
uint64_t ASSETCHAINS_ENDSUBSIDY,ASSETCHAINS_REWARD,ASSETCHAINS_HALVING,ASSETCHAINS_DECAY,ASSETCHAINS_COMMISSION,ASSETCHAINS_STAKED,ASSETCHAINS_SUPPLY = 10;

uint32_t SAFECOIN_INITDONE;
char SAFEUSERPASS[8192],BTCUSERPASS[8192]; uint16_t SAFE_PORT = 7771,BITCOIND_RPCPORT = 7771;
uint64_t PENDING_SAFECOIN_TX;
extern int32_t SAFECOIN_LOADINGBLOCKS;
unsigned int MAX_BLOCK_SIGOPS = 20000;

struct safecoin_kv *SAFECOIN_KV;
pthread_mutex_t SAFECOIN_KV_mutex,SAFECOIN_CC_mutex;
