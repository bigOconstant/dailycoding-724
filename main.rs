struct Node {
    val:  String,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn evaluate(&self)->i32 {
        match &self.val[..] {
           "*"=> {
                return self.left.as_ref().unwrap().evaluate() * self.right.as_ref().unwrap().evaluate()
           }
           "+" => {
            return self.left.as_ref().unwrap().evaluate() + self.right.as_ref().unwrap().evaluate()
           }
           "-" => {
            return self.left.as_ref().unwrap().evaluate() - self.right.as_ref().unwrap().evaluate()
           }
           "/" => {
            return self.left.as_ref().unwrap().evaluate() / self.right.as_ref().unwrap().evaluate()
           }
           
            _ => return self.val.parse::<i32>().unwrap(),           
        }  
    }

    fn new(val:&str)->Node {
         return  Node{val:val.to_string(),left:None,right:None}
    }
    
}

fn main() {
    let mut root =  Node::new("*");
    root.left = Some(Box::new(Node::new("+")));
    root.right = Some(Box::new(Node::new("+")));
    root.left.as_mut().unwrap().left = Some(Box::new(Node::new("3")));
    root.left.as_mut().unwrap().right = Some(Box::new(Node::new("2")));
    root.right.as_mut().unwrap().right = Some(Box::new(Node::new("5")));
    root.right.as_mut().unwrap().left = Some(Box::new(Node::new("4")));
    println!("answer:{}",root.evaluate());
}