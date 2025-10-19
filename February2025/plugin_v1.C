#include <SOP/SOP_Node.h>
#include <UT/UT_Vector3.h>
#include <GA/GA_Handle.h>
#include <OP/OP_Operator.h>
#include <OP/OP_OperatorTable.h>

class SOP_MovePoint : public SOP_Node {
public:
    static OP_Node *myConstructor(OP_Network *net, const char *name, OP_Operator *op) {
        return new SOP_MovePoint(net, name, op);
    }
    static PRM_Template myTemplateList[];

protected:
    SOP_MovePoint(OP_Network *net, const char *name, OP_Operator *op)
        : SOP_Node(net, name, op) {}

    virtual ~SOP_MovePoint() {}

    virtual OP_ERROR cookMySop(OP_Context &context) override;

private:
    UT_Vector3 getMoveVector();
};

static PRM_Name moveName("move", "Move Vector");

PRM_Template SOP_MovePoint::myTemplateList[] = {
    PRM_Template(PRM_XYZ, 3, &moveName, PRMzeroDefaults),
    PRM_Template()
};

UT_Vector3 SOP_MovePoint::getMoveVector() {
    UT_Vector3 move(
        evalFloat("move", 0, 0),
        evalFloat("move", 1, 0),
        evalFloat("move", 2, 0)
    );
    gdp->setPos3(0, move);
    return move;
}

OP_ERROR SOP_MovePoint::cookMySop(OP_Context &context) {
    // Clear and prepare geometry
    gdp->clearAndDestroy();

    // Get movement vector from parameter
    UT_Vector3 move = getMoveVector();

    // Create a point at the origin and move it
    GA_Offset ptoff = gdp->appendPoint();
    gdp->setPos3(ptoff, move);

    return error();
}

void newSopOperator(OP_OperatorTable *table) {
    table->addOperator(new OP_Operator(
        "move_point",
        "Move Point",
        SOP_MovePoint::myConstructor,
        SOP_MovePoint::myTemplateList,
        0, // Min inputs
        0, // Max inputs
        nullptr, // Local variables
        OP_FLAG_GENERATOR // Node flag
    ));
}

