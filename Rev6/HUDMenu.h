//
//  HUDMenu.h
//  Rev5
//
//  Created by Bryce Redd on 3/1/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "cocos2d.h"
#import "Box2D.h"

@class HUDItem, ButtonItem, BuildItem, StatusItem, GoldItem, PurchaseItem, Piece;

@interface HUDMenu : NSObject {
	float extremeRight;
	NSDictionary *managers;
	BOOL hasBack;
}

@property(nonatomic, retain) HUDItem *selected;
@property(nonatomic, retain) NSMutableArray* items;

-(id) initWithManagers:(NSDictionary*)mans;
-(HUDItem *) getHUDItem:(CGPoint)p;
-(void) moveAllObjects:(CGPoint)p;
-(GoldItem *) addGoldStatusWithLeft:(float)l;
-(void) addItemWithManagerName:(NSString *)mgrName 
					  imageBox:(CGRect)box 
				 swingImageBox:(CGRect)swingBox 
					   hudItem:(HUDItem*)item 
			expandToStatusSize:(BOOL)expand;

-(StatusItem *) addStatusItemWithManagerName:(NSString *)mgrName 
									imageBox:(CGRect)box 
							   swingImageBox:(CGRect)swingBox 
									   piece:(Piece*)p;

-(ButtonItem *) addButtonItemWithManagerName:(NSString *)mgrName 
							imageBox:(CGRect)box 
					   swingImageBox:(CGRect)swingBox 
							selector:(SEL)s 
							   title:(NSString*)t;

-(BuildItem *) addBuildItemWithManagerName:(NSString *)mgrName 
								imageBox:(CGRect)box 
						   swingImageBox:(CGRect)swingBox 
								   class:(Class)c price:(int)p;

-(PurchaseItem *) addPurchaseItemWithManagerName:(NSString *)mgrName 
										imageBox:(CGRect)box 
								   swingImageBox:(CGRect)swingBox 
										selector:(SEL)s 
										   title:(NSString*)t 
										   piece:(Piece*)p;

-(void) setSwingItemWithManager:(AtlasSpriteManager*)mgr 
					   swingBox:(CGRect)swingBox 
					   imageBox:(CGRect)box 
						forItem:(HUDItem*)item 
					   forClass:(Class)c;

-(void) hideAll;
-(void) showAll;

-(BOOL) handleInitialTouch:(CGPoint)p;
-(BOOL) handleTouchDrag:(CGPoint)p;
-(BOOL) handleDragExit:(CGPoint)p;
-(BOOL) handleEndTouch:(CGPoint)p;
-(CGRect) hudRect;
@end
